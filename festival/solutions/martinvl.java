/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.util.Scanner;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        double[][] coords = new double[n][2];

        for (int i = 0; i < n; ++i) {
            coords[i][0] = Double.parseDouble(in.next());
            coords[i][1] = Double.parseDouble(in.next());
        }

        double A = 0;

        for (int i = 0; i < n; ++i) {
            A += coords[i][0]*coords[(i+1)%n][1] - coords[(i+1)%n][0]*coords[i][1];
        }

        A = A < 0 ? -A : A;

        System.out.println(.5*A);
    }
}
