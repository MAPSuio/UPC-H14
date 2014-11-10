/*
@EXPECTED_RESULTS@: WRONG_ANSWER
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int num_smaller = 0;

    for (int i = 0; i < n; ++i) {
        float value;
        char buf[50];
        scanf("%s %f", buf, &value);

        if (value < 5790) {
            ++num_smaller;
        }
    }

    if (n - num_smaller - 1) {
        printf("%d\n", n - num_smaller);
    } else {
        printf("STEAL THE PHONE\n");
    }

    return 0;
}
