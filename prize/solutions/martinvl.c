/*
@EXPECTED_RESULTS@: CORRECT
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int num_larger = 0;

    for (int i = 0; i < n-1; ++i) {
        double value;
        char buf[50];
        scanf("%s %lf", buf, &value);

        if (value > 5790) {
            ++num_larger;
        }
    }

    if (num_larger) {
        printf("%d\n", num_larger + 1);
    } else {
        printf("STEAL THE PHONE\n");
    }

    return 0;
}
