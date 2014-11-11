/*
# @EXPECTED_RESULTS@: CORRECT
*/
#include <stdio.h>
#include <string.h>

int main() {
	int n, place = 1;
	double iphone = 5790.000000, tmp;
	char name[51];

	scanf("%d", &n);
	n--;

	// Read and find the iphone
	for(;n;n--) {
		scanf("%s", name);
		scanf("%lf", &tmp);
		if(tmp > iphone)
			place++;
	}

	if(place == 1)
		printf("STEAL THE PHONE\n");
	else
		printf("%d\n", place);

	return 0;
}
