/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.util.Scanner;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt();
        int m = in.nextInt();
        int n = in.nextInt();

        System.out.printf("%08d\n", keanucci(d, m, n));
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
            int cur = (pprev + prev) % (int)1e8;
            pprev = prev;
            prev = cur;
        }

        return prev;
    }
}
