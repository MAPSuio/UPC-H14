/*
@EXPECTED_RESULTS@: CORRECT
 * Idea: Calculate the polygon by triangles, until only two points remain, then return the absolute value
 *
 * points: a b c d e f g
 * ......> a c d e f g
 * ......> a d e f g
 * ......> a e f g
 * ......> a f g
 * ......> solution
 *
 * Additionally, do the edge sum to find out which direction the graph is going.
 * This means it will ignore triangles going outside
 */

#include <stdio.h>

typedef struct point_t point;
struct point_t {
	double x, y;
};

// http://www.mathopenref.com/coordtrianglearea.html
inline double trianglesum(point a, point b, point c) {
	// absolute value of:
	// ax(by-cy) + Bx(cy-ay) + Cx(ay-by) / 2
	double ai = b.y - c.y;
	double bi = c.y - a.y;
	double ci = a.y - b.y;
	return ((a.x*ai) + (b.x*bi) + (c.x * ci)) / (double)2.0;
}

// http://stackoverflow.com/questions/1165647/how-to-determine-if-a-list-of-polygon-points-are-in-clockwise-order
inline double edgesum(point a, point b) {
	double x = b.x - a.x;
	double y = b.y + a.y;
	return x*y;
}

int main() {
	int n;
	double area = 0, direction = 0;
	point a, b, c;

	scanf("%d", &n);
	scanf("%lf %lf", &a.x, &a.y);
	scanf("%lf %lf", &b.x, &b.y);

	direction += edgesum(a,b);
	n -= 2;
	while(n > 0) {
		// read into c
		scanf("%lf %lf", &c.x, &c.y);

		// calculate into tmp
		area += trianglesum(a,b,c);

		// calculate the edge
		direction += edgesum(b,c);

		// move c to b
		b.x = c.x;
		b.y = c.y;
		n--;
	}
	direction += edgesum(b, a);

	if(direction > 0) area = -area;
	printf("%lf\n", area);
	return 0;
}
