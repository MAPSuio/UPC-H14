#include <stdio.h>
#include <stdlib.h>

/* Queue stuff: insersions in back, removing in front */
typedef struct qe_t qe;
struct qe_t {
    int card;
    qe *next;
};
typedef struct queue_t {
    qe *start;
    qe *end;
} queue;
void q_i(queue *q){
    q->start = NULL;
    q->end = NULL;
}
qe *q_gen(int card) {
    qe *q = malloc(sizeof(qe));
    q->next = NULL;
    q->card = card;
    return q;
}
void q_in(queue *q, qe *elem) {
    if(q->end == NULL) {
        q->start = q->end = elem;
        elem->next = NULL;
    } else {
        q->end->next = elem;
        q->end = elem;
        elem->next = NULL;
    }
}
qe *q_rem(queue *q) {
    /* Remove from top */
    qe *elem;
    if(!q->start) return NULL;
    elem = q->start;
    q->start = elem->next;
    if(!q->start) q->end = NULL;
    return elem;
}

typedef struct testcase_t {
    int p1;
    int p2;
    int *p1a;
    int *p2a;
} testcase;

int test(testcase *t, unsigned long long *iter) {
    queue p1stack, p2stack, p1bet, p2bet;
    qe *p1card = NULL, *p2card = NULL, *tmp;
    int i, j;
    *iter = 0;

    q_i(&p1stack);
    q_i(&p2stack);
    q_i(&p1bet);
    q_i(&p2bet);

    for(i=0;i<t->p1;i++) {
        q_in(&p1stack, q_gen(t->p1a[i]));
    }
    for(i=0;i<t->p2;i++) {
        q_in(&p2stack, q_gen(t->p2a[i]));
    }

    while(p1stack.start && p2stack.start) {
        p1card = q_rem(&p1stack);
        p2card = q_rem(&p2stack);
        if(p1card->card == p2card->card) {
            q_in(&p1bet, p1card);
            q_in(&p2bet, p2card);
            for(i=0;i<3;i++) {
                if((p1card = q_rem(&p1stack)))
                    q_in(&p1bet, p1card);
                if((p2card = q_rem(&p2stack)))
                    q_in(&p2bet, p2card);
            }
        } else if(p1card->card > p2card->card) {
            while((tmp = q_rem(&p1bet)))
                q_in(&p1stack, tmp);
            q_in(&p1stack, p1card);

            while((tmp = q_rem(&p2bet)))
                q_in(&p1stack, tmp);
            q_in(&p1stack, p2card);
        } else /* if(p2card->card > p1card->card) */ {
            while((tmp = q_rem(&p2bet)))
                q_in(&p2stack, tmp);
            q_in(&p2stack, p2card);

            while((tmp = q_rem(&p1bet)))
                q_in(&p2stack, tmp);
            q_in(&p2stack, p1card);
        }
        *iter = *iter+1;
    }
    i = p1stack.start != NULL ? 1 : 0;
    j = p2stack.start != NULL ? 1 : 0;
    while((tmp = q_rem(&p2bet)))   free(tmp);
    while((tmp = q_rem(&p1bet)))   free(tmp);
    while((tmp = q_rem(&p2stack))) free(tmp);
    while((tmp = q_rem(&p1stack))) free(tmp);

    if(i == 0 && j == 0) {
        return  0; // draw
    } else if(i == 0) {
        return -1; // player2
    } else /* if(j == 0) */ {
        return 1; // player1
    }
}

void printcase(testcase *t, int ret, const char *prefix) {
    int i;
    static int no = 1;
    char fname[256];
    FILE *fp;
    printf("Testcase %03i - %s\n", no, prefix);
    snprintf(fname, sizeof(fname), "%s-%06i.in", prefix, no);
    fp = fopen(fname, "w");

    fprintf(fp, "%i\n", t->p1);
    fprintf(fp, "%i\n", t->p2);
    for(i=0;i<t->p1;i++) {
        fprintf(fp, "%i ", t->p1a[i]);
    }
    fprintf(fp, "\n");
    for(i=0;i<t->p2;i++) {
        fprintf(fp, "%i ", t->p2a[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
    snprintf(fname, sizeof(fname), "%s-%06i.out", prefix, no);
    fp = fopen(fname, "w");
    if(ret == 1)
	    fprintf(fp, "PLAYER1\n");
    else if(ret == 0)
	    fprintf(fp, "draw\n");
    else if(ret == -1)
	    fprintf(fp, "PLAYER2\n");
    fclose(fp);

    no++;
}
void shuffle(int *a, int l) {
    int i, j, tmp;
    if(l <= 1) return;
    for(i = 0; i < l-1; i++) {
        j = i + rand() / (RAND_MAX/(l-i)+1);
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
    }
}
/*
1 - Player1
2 - Player2
d - draw

* predecided winner - 1, 2, d
*      1 iteration - 1, 2, d
*     10 iterations - 1, 2, d
*    100 iterations - 1, 2, d
*   1000 iterations - 1, 2, d
*  10000 iterations - 1, 2, d
*  90000 iterations - 1, 2, d * 10
* 100000 iterations - (give up even though there is a winner) - 1, 2
* 110000 iterations - 1, 2, d
*/

typedef struct trial_t {
	unsigned long long max, min;
	const char *prefix;
	int remain1, remain2, remaind;
} trial;

const int numtrials = 0;
trial trials[] = {
//	{0,           0, "predecided", 1,  1,  1}, manually crafted
//	{1,           1, "1i",         1,  1,  1}, DONE with 2 % 2 and 2 % 1
//	{8,          12, "10i",        1,  1,  1}, DONE with 1 stack
//	{80,        120, "100i",       1,  1,  1}, DONE with 1 stack
//	{400,       800, "600i",       0,  0,  4}, DONE with 52 % 8
//	{800,      1200, "1000i",      1,  1,  0}, DONE with 1 stack
//	{8000,    12000, "10000i",     1,  1,  0}, DONE with 2 stacks
//	{90000,   95000, "90000i",    10, 10,  0}, DONE with 6 stacks
//	{100000, 100000, "100000i",    0,  0,  1}, DONE with 8*52 % 8*26
//	{110000, 120000, "110000i",    0,  0,  1}, same
};
int totrem = 0;

void set_totrem(){
	int i;
	totrem = 0;
	for(i=0;i<numtrials;i++) {
		totrem += trials[i].remain1;
		totrem += trials[i].remain2;
		totrem += trials[i].remaind;
	}
}

int match_trial(testcase *tc, int ret, unsigned long long iter){
	int i;
	trial *t = NULL;
	int *rem = NULL;
	for(i=0;i<numtrials;i++){
		if(trials[i].min >= iter && trials[i].max <= iter) {
			t = &trials[i];
			break;
		}
	}
	// No matching iter
	if(!t) return -1;

	if(ret == 0)       rem = &t->remaind;
	else if(ret == 1)  rem = &t->remain1;
	else if(ret == -1) rem = &t->remain2;

	// no remainder
	if(!rem) return -2;

	// We have what we need
	if(*rem < 1) return -3;

	*rem = *rem-1;
	totrem--;

	printcase(tc, ret, t->prefix);
	return 0;
}

/* Highest complexities list given stacks:
 * 1: 2000 - 2600 possible
 * 2: 12000 - 13000 possible
 * 4: 50k - 55k
 * 6: 126k
 * 9:  200k
 * 500 % 100: 300k
 * 10: 300k
 * 20: 1.3M
 * */

// #define STACKS 8

// #define UNIQ (STACKS*13)
// #define CARDS (STACKS*52)
#define UNIQ 2
#define CARDS 2

// >= this, draw
#define ROUNDLIMIT 100000
int main(int argc, char **argv){
    testcase t;
    int i, ret;
    unsigned long long iter, highest = 0, lowest = -1;
    if(argc < 2) {
        fprintf(stderr, "USAGE: %s <rand seed>\n", argv[0]);
        return 1;
    }
    set_totrem();
    t.p1 = t.p2 = CARDS/2;
    t.p1a = malloc(sizeof(int)*(t.p1+t.p2));
    t.p2a = t.p1a+t.p1;
    srand(atoi(argv[1]));
    for(i=0;i<(t.p1+t.p2);i++){
        // initialize the 52 card deck
        t.p1a[i] = i % UNIQ;
    }
    while(totrem) {
        shuffle(t.p1a, t.p1+t.p2);
        ret = test(&t, &iter);

	if(iter >= ROUNDLIMIT) ret = 0;
	if(iter == 100000) printf("Woow!\n");

	match_trial(&t, ret, iter);
	if(iter > highest) {
		highest = iter;
		printf("Highest iter: %llu\n", highest);
	}
	if(iter < lowest) {
		lowest = iter;
		printf("Lowest iter: %llu\n", lowest);
	}
    }

    free(t.p1a);
    return 0;
}
