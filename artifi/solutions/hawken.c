/*
@EXPECTED_RESULTS@: CORRECT
*/

#include <stdio.h>

int main() {
	char buf[10];
	scanf("%s", buf);
	if(!strcmp(buf, "no")) printf("yes\n");
	else printf("no\n");
	return 0;
}
