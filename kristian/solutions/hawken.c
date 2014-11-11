/*
# @EXPECTED_RESULTS@: CORRECT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0

/* QUEUE STUFF */
/* It will free for you if you don't do it yourself. Neat! */
typedef struct queue_t queue;

queue *queue_init(int size);
void queue_destroy(queue *q);
void queue_add(queue *q, void *item);
void *queue_get(queue *q);
bool queue_empty(queue *q);

struct queue_t {
	int count;
	int size;
	int first;
	int last;
	void **q;
};
queue *queue_init(int size){
	queue *q = malloc(sizeof(queue));
	q->q = malloc(sizeof(void *)*size);
	q->size = size;
	q->last = size-1;
	q->first = 0;
	q->count = 0;
	return q;
}
void queue_destroy(queue *q) {
	while(!queue_empty(q))
		free(queue_get(q));
	free(q->q);
	free(q);
}
void queue_add(queue *q, void *item) {
	if(q->count >= q->size){
		printf("Queue overflow!\n");
		return;
	}
	q->last = (q->last+1) % q->size;
	q->q[q->last] = item;
	q->count = q->count+1;
}
void *queue_get(queue *q) {
	void *x;
	if(q->count <= 0) {
		printf("Tried get on empty queue\n");
		return NULL;
	}
	x = q->q[q->first];
	q->first = (q->first+1) % q->size;
	q->count -= 1;
	return x;
}
bool queue_empty(queue *q) {
	if(q->count <= 0) return true;
	return false;
}
/* /QUEUE STUFF */

/* GRID STUFF */
typedef struct grid_t grid;

grid *grid_init(int x, int y);
void grid_reset(grid *g);
void grid_destroy(grid *g);
void grid_set(grid *g, int x, int y, bool state);
bool grid_get(grid *g, int x, int y);

struct grid_t {
	int y;
	int x;
	/* Grid is accessed like: grid.g[y][x] */
	/* true for open, false for closed */
	bool **g;
};

grid *grid_init(int x, int y) {
	int i;
	grid *g = malloc(sizeof(grid));
	g->x = x;
	g->y = y;
	g->g = malloc(sizeof(bool *)*y);
	for(i=0;i<y;i++)
		g->g[i] = malloc(sizeof(bool)*x);
	grid_reset(g);
	return g;
}

void grid_reset(grid *g) {
	int i, j;
	for(i=0;i<g->y;i++)
		for(j=0;j<g->x;j++)
			g->g[i][j] = true;
}

void grid_destroy(grid *g) {
	int i;
	for(i=0;i<g->y;i++)
		free(g->g[i]);
	free(g->g);
	free(g);
}

void grid_set(grid *g, int x, int y, bool state) {
	g->g[y][x] = state;
}

bool grid_get(grid *g, int x, int y) {
	return g->g[y][x];
}
/* /GRID STUFF */

int transit(grid *g, int x1, int y1, int x2, int y2) {
	struct elem_t {
		int x;
		int y;
		char sign;
	};
	struct elem_t *e, *e2;
	queue *q;
	int *g2;
	int i, j, v, a;
	// If it's on top of us, don't go
	// on top of each other: return 0 because they are already there
	if(x1 == x2 && y1 == y2) {
		return 0;
	}

	// directly above or below or to the sides
	if(((x1+1 == x2 || x1-1 == x2) && y1 == y2)
	|| ((y1+1 == y2 || y1-1 == y2) && x1 == x2)) {
		return 1;
	}

	// run a BFS from both sides
       	q = queue_init(g->x*g->y);
	g2 = malloc(sizeof(int)*g->x*g->y);

	for(i=0;i<g->y;i++)
		for(j=0;j<g->x;j++)
			g2[(i*g->x) + j] = 0;

	e = malloc(sizeof(struct elem_t));
	e->x = x1;
	e->y = y1;
	e->sign = 1;
	queue_add(q, e);

	e = malloc(sizeof(struct elem_t));
	e->x = x2;
	e->y = y2;
	e->sign = -1;
	queue_add(q, e);

	while(!queue_empty(q)) {
		e = queue_get(q);
		// y shift
		for(i=-1; i < 2; i++) {
			// x shift
			for(j=-1;j<2;j++) {
				// skip this case
				if(i==0 && j==0) continue;
				// one direction at a time
				if(i != 0 && j != 0) continue;

				e2 = malloc(sizeof(struct elem_t));
				e2->sign = e->sign;
				e2->x = e->x + j;
				e2->y = e->y + i;
				// out of bounds
				if(e2->y < 0)     goto no;
				if(e2->y >= g->y) goto no;
				if(e2->x < 0)     goto no;
				if(e2->x >= g->x) goto no;
				// we cannot touch this intersection
				if(!grid_get(g, e2->x, e2->y)) goto no;
				// Check if it's opposite, zero or same
				v = g2[(e2->y*g->x) + e2->x];
				if((e->sign * v) > 0) goto no;
				if(v == 0) {
					g2[(e2->y*g->x) + e2->x] = g2[(e->y*g->x) + e->x] + e->sign;
					printf("(%i, %i) -> (%i, %i) (%i)\n", e->x, e->y, e2->x, e2->y,
							g2[(e2->y*g->x)+e2->x]);
					queue_add(q, e2);
					continue;
				}
				if(e->sign * v < 0) { // different side
					a = g2[(e->y*g->x) + e->x] + e->sign;
					if(a < 0) a = -a;
					if(v < 0) v = -v;
					free(g2);
					free(e2);
					free(e);
					queue_destroy(q);
					return a+v;
				}
no:
				free(e2);
			}
		}
		free(e);
	}
	free(g2);
	queue_destroy(q);
	return -1;
}

int main() {
	int x, y, m, i, x2, y2, r;
	char buf[20];
	// true = open
	grid *g;

	scanf("%d %d %d", &x, &y, &m);
	g = grid_init(x,y);

	for(i=0;i<m;i++) {
		scanf("%s", buf);
		if(!strcmp(buf, "CLOSED")) {
			scanf("%d %d", &x, &y);
			grid_set(g, x, y, false);
		} else if(!strcmp(buf, "REQUEST")) {
			scanf("%d %d %d %d", &x, &y, &x2, &y2);
			r = transit(g, x, y, x2, y2);
			if(r == -1) printf("STAY WHERE YOU ARE\n");
			else printf("%i\n", r);
		} else if(!strcmp(buf, "OPENED")) {
			scanf("%d %d", &x, &y);
			grid_set(g, x, y, true);
		} else {
			printf("UNKNOWN event: %s\n", buf);
			return 1;
		}
	}

	grid_destroy(g);
	return 0;
}
/*
X, Y, M = map(int, stdin.next().split())

opened = [[True]*Y for i in xrange(X)]

def bfs(start, goal):
    global opened, X, Y
    dist = [[-1]*Y for i in xrange(X)]

    dist[start[0]][start[1]] = 0
    q = [start]

    while q:
        nq = []

        for p in q:
            if p == goal:
                return dist[goal[0]][goal[1]]

            for dp in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                np = (p[0] + dp[0], p[1] + dp[1])

                if np[0] < 0 or np[0] >= X or np[1] < 0 or np[1] >= Y:
                    continue

                if dist[np[0]][np[1]] == -1 and opened[np[0]][np[1]]:
                    dist[np[0]][np[1]] = dist[p[0]][p[1]] + 1
                    nq.append(np)

        q = nq

    return -1

for data in (line.split() for line in stdin):
    if data[0] == 'OPENED' or data[0] == 'CLOSED':
        x, y = map(int, data[1:])
        opened[x][y] = data[0] == 'OPENED'
    else:
        x1, y1, x2, y2 = map(int, data[1:])
        dist = bfs((x1, y1), (x2, y2))

        if dist == -1:
            print 'STAY WHERE YOU ARE'
        else:
            print dist
	    */
