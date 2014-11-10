/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.util.Scanner;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // skip the first two numbers in input
        in.next(); in.next();

        String j = in.next();
        String g = in.next();

        System.out.println(g.substring(0, g.length() - j.length()) + j.substring(0, j.length()-1));
    }
}
