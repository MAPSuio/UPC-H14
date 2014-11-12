/*
@EXPECTED_RESULTS@: CORRECT
 * Do the shoelace formula
 *
 * Additionally, do the edge sum to find out which direction the graph is going.
 * This means it will ignore triangles going outside
 */

#include <stdio.h>

#define fl long double

typedef struct point_t point;
struct point_t {
	fl x, y;
};

// http://en.wikipedia.org/wiki/Shoelace_formula
inline fl edgesum(point a, point b) {
	fl x = a.x*b.y;
	fl y = b.x*a.y;
	return x - y;
}

int main() {
	int n;
	fl area = 0;
	point a, b, c;

	scanf("%d", &n);
	scanf("%Lf %Lf", &a.x, &a.y);
	scanf("%Lf %Lf", &b.x, &b.y);

	area += edgesum(a,b);
	n -= 2;
	while(n > 0) {
		// read into c
		scanf("%Lf %Lf", &c.x, &c.y);

		// calculate the edge
		area += edgesum(b,c);

		// move c to b
		b.x = c.x;
		b.y = c.y;
		n--;
	}
	area += edgesum(b, a);

	area = ((area < 0) ? -area : area) / (fl)2;
	printf("%.8Lf\n", area);
	return 0;
}
