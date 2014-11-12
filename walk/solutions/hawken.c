/*
# @EXPECTED_RESULTS@: CORRECT
*/

//

#include <stdio.h>

int main(){
	int n, b, a = 1;

	scanf("%d", &n);

	for (n++; n; n--) {
		scanf("%d", &b);
		if(b == 1) a = !a;
		else break;
	}

	printf("%s\n", a ? "Angwusnasomtaqa" : "Bob");

	return 0;
}

