/*
@EXPECTED_RESULTS@: WRONG-ANSWER, RUN-ERROR
*/

import java.util.Scanner;

public class martinvl_overflow {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt();
        int m = in.nextInt();
        int n = in.nextInt();

        System.out.printf("%08d\n", keanucci(d, m, n) % (int)1e8);
    }

    static int keanucci(int d, int m, int n) {
        if (n == 0) {
            return d;
        }

        if (n == 1) {
            return m;
        }

        int pprev = d;
        int prev = m;

        for (int i = 2; i <= n; ++i) {
            // this will overflow at some point
            int cur = pprev + prev;
            pprev = prev;
            prev = cur;
        }

        return prev;
    }
}
