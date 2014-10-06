/*
# @EXPECTED_RESULTS@: WRONG-ANSWER
*/

import java.util.Scanner;

public class martinvl_wrong {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // skip the first two numbers in input
        in.next(); in.next();

        long j = in.nextLong(2);
        long g = in.nextLong(2);
        long mean = (j + g)/2;

        System.out.println(Long.toBinaryString(mean));
    }
}
