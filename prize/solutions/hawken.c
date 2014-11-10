/*
# @EXPECTED_RESULTS@: CORRECT
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	int n, i, j, place = 1;
	double iphone = -1, *p, tmp;
	char name[51];

	scanf("%d", &n);
	p = malloc(sizeof(iphone) * (n-1));
	j = 0;

	// Read and find the iphone
	for(i=0;i<n;i++) {
		scanf("%s", name);
		scanf("%lf", &tmp);
		if(!strcmp(name, "iPhone"))
			iphone = tmp;
		else
			p[j++] = tmp;
	}

	// Count the number of prices bigger than iphone
	for(i=0;i<j;i++)
		if(p[i] > iphone)
			place++;

	if(place == 1)
		printf("STEAL THE PHONE\n");
	else
		printf("%d\n", place);

	free(p);
	return 0;
}
