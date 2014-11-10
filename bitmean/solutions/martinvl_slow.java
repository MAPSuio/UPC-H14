/*
@EXPECTED_RESULTS@: TIMEOUT, RUN-ERROR
*/

import java.util.Scanner;
import java.math.BigInteger;

public class martinvl_slow {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // skip the first two numbers in input
        in.next(); in.next();

        final int radix = 2;
        final BigInteger TWO = new BigInteger("2");

        BigInteger j = new BigInteger(in.next(), radix);
        BigInteger g = new BigInteger(in.next(), radix);
        BigInteger mean = j.add(g).divide(TWO);

        System.out.println(mean.toString(radix));
    }
}
