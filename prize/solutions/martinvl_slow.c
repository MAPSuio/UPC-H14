/*
@EXPECTED_RESULTS@: TIMELIMIT
*/

#include <stdio.h>
#define MAX_N 10001

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    // read patients
    double p[MAX_N];
    for (int i = 0; i < n-1; ++i) {
        char buf[50];
        scanf("%s %lf", buf, p+i);
    }

    p[n-1] = 5790;

    // sort patients, slowly
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (p[i] < p[j]) {
                double tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    int place;
    for (; place < n; ++place) {
        if (p[place] == 5790) {
            break;
        }
    }

    if (place) {
        printf("%d\n", place + 1);
    } else {
        printf("STEAL THE PHONE\n");
    }

    return 0;
}
