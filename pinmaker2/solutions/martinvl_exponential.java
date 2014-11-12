/*
@EXPECTED_RESULTS@: TIMELIMIT
*/

import java.util.Scanner;

public class martinvl_exponential {
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

        return (keanucci(d, m, n-1) + keanucci(d, m, n-2)) % (int)1e8;
    }
}
