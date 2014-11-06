#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

unsigned long hash(unsigned char *str) {
	unsigned long hash = 545512235381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash;
}

int main() {
	
	char a = (char) 0x12 + 65;
	char b = (char) 0x04 + 65;

	char* s = "alittlestring";
	char* input = malloc(strlen(s) + 2);

	printf("%d\n", strlen(s));

	sprintf(input, "%s%c%c\0", s, a, b);

	printf("%d\n", strlen(input));
	printf("%s\n", input);
	printf("%d\n", hash(s));

	char str[100];
	sprintf(str, "%d", hash(s));
	printf(str);

	free(input);
}
