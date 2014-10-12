/*
@EXPECTED_RESULTS@: TIMEOUT
*/

import java.math.BigInteger;
import java.util.Scanner;

public class martinvl_linear {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt();
        int m = in.nextInt();
        String n = in.next();

        System.out.printf("%08d\n", keanucci(d, m, n));
    }

    static int keanucci(int d, int m, String k) {
        if (k.equals("0")) {
            return d;
        }

        if (k.equals("0")) {
            return m;
        }

        int pprev = d;
        int prev = m;
        BigInteger n = new BigInteger(k).subtract(BigInteger.ONE);

        for (; n.compareTo(BigInteger.ZERO) > 0; n = n.subtract(BigInteger.ONE)) {
            int cur = (pprev + prev) % (int)1e8;
            pprev = prev;
            prev = cur;
        }

        return prev;
    }
}
