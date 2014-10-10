/*
@EXPECTED_RESULTS@: TIMEOUT
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

    int pprev = d;
    int prev = m;

    for (int i = 2; i <= n; ++i) {
        int cur = (pprev + prev) % (int)1e8;
        pprev = prev;
        prev = cur;
    }

    return prev;
}

int main(int argc, char* argv[])
{
    int d, m, n;
    scanf("%d %d %d", &d, &m, &n);

    printf("%08d\n", keanucci(d, m, n));

    return 0;
}
