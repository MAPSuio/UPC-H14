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

int main(int argc, char *argv[]) {
	
	char a = (char) 0x11 + 65;
	char b = (char) 0x4 + 65;

	char* s = "alittlestring";

	char* input = malloc(strlen(s) + 2);
	sprintf(input, "%s%c%c\0", s, a, b);

	//char* input2 = malloc(strlen(s) + 2);
	//sprintf(input2, "%s%s%s\0", s, argv[1], argv[2]);
	//printf(input2);


//	printf("%d\n", strlen(input));
//	printf("%s\n", input);
//	printf("%d\n", hash(s));

	char str[100];
	char str2[100];
	sprintf(str, "%d\n", hash(input));
	printf(str);

	//printf(str2, "%d\n", hash(input2));
	//printf(str2);

	free(input);
}
