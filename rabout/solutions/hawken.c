/*
@EXPECTED_RESULTS@: TIMELIMIT
*/

#include <stdio.h>
#include <string.h>

/* Max number of needed iterations: size/2
 * */

#define WRAP(x) (((x)+size) % size)

int main(){
	char buf[100010], buf2[100010];
	int i,l=0,r=0,size;

	scanf("%s", buf);
	for(i=0;;i++) {
		if(buf[i] == 'L') l++;
		else if(buf[i] == 'R') r++;
		else {
			buf[i] = 0;
			break;
		}
	}
	size = strlen(buf);
	buf2[size] = 0;
	for(i=0;l && r;i++) {
		int j;
		//printf("%s (r %i l %i)\n", buf, r, l);
		memset(buf2, '-', size);
		// zero initialize
		for(j=0;j<size; j++) {
			if(buf[WRAP(j+1)] != 'L' && buf[WRAP(j-1)] != 'R') {
				buf2[j] = '-';
				continue;
			}
			if(buf[WRAP(j+1)] == 'L') {
				if(buf[j] == 'R') {
					// anhilation time
					buf[j] = '-';
					buf[WRAP(j+1)] = '-';

					buf2[j] = '-';
					buf2[WRAP(j+1)] = '-';
					l--;
					r--;
				} else {
					buf2[j] = 'L';
				}
			}
			if(buf[WRAP(j-1)] == 'R') {
				buf2[j] = 'R';
			}
		}
		memcpy(buf,buf2,size);
	}
	if(!r && !l) {
		printf("Too Bad\n");
	} else if(l) {
		int j;
		i = WRAP(i);
		for(j=0;j<size;j++) {
			if(buf[WRAP(j-i)] == 'L') {
				printf("%i ", j);
			}
		}
		printf("\n");
	} else {
		int j;
		i = WRAP(i);
		for(j=0;j<size;j++) {
			if(buf[WRAP(j+i)] == 'R') {
				printf("%i ", j);
			}
		}
		printf("\n");
	}
	// shift length in i

	return 0;
}
