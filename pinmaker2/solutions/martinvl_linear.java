/*
@EXPECTED_RESULTS@: TIMEOUT
*/

import java.util.Scanner;

public class martinvl_linear {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt();
        int m = in.nextInt();
        long n = in.nextLong();

        System.out.printf("%08d\n", keanucci(d, m, n));
    }

    static int keanucci(int d, int m, long n) {
        if (n == 0) {
            return d;
        }

        if (n == 1) {
            return m;
        }

        int pprev = d;
        int prev = m;
        --n;

        for (; n > 0; --n) {
            int cur = (pprev + prev) % (int)1e8;
            pprev = prev;
            prev = cur;
        }

        return prev;
    }
}
