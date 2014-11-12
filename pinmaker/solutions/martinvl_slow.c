/*
@EXPECTED_RESULTS@: TIMELIMIT
*/

#include <stdio.h>

int keanucci(int d, int m, int n)
{
    if (n == 0) {
        return d;
    }

    if (n == 1) {
        return m;
    }

    return (keanucci(d, m, n-1) + keanucci(d, m, n-2))%(int)1e8;
}

int main(int argc, char* argv[])
{
    int d, m, n;
    scanf("%d %d %d", &d, &m, &n);

    printf("%08d\n", keanucci(d, m, n));

    return 0;
}
