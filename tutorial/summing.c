#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = 0; j < 10; ++j) {
            int num;
            scanf("%d", &num);

            sum += num;
        }

        printf("%d\n", sum);
    }

    return 0;
}
