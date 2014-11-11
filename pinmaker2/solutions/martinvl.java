/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.util.Scanner;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt();
        int m = in.nextInt();
        long n = in.nextLong();

        System.out.printf("%08d\n", keanucci(d, m, n));
    }

    static final int p = (int)1e8;

    static int keanucci(int d, int m, long n) {
        if (n == 0) {
            return d;
        }

        if (n == 1) {
            return m;
        }

        // need long to be able to hold (10^8)^2
        long[][] mat = new long[][]{new long[]{1, 1}, new long[]{1, 0}};
        long[] vec = new long[]{m, d};

        return (int)matVecProd(matExp(mat, n-1), vec)[0];
    }

    // calculate mat^n for 2x2 matrix, n >= 1
    static long[][] matExp(long[][] mat, long n) {
        long[][] res = new long[][]{new long[]{1, 0}, new long[]{0, 1}};

        while (n > 0) {
            if (n % 2 == 1) {
                res = matProd(res, mat);
            }

            mat = matProd(mat, mat);
            n /= 2;
        }

        return res;
    }

    // calculate matrix product of two 2x2 matrices
    static long[][] matProd(long[][] lhs, long[][] rhs) {
        long[][] res = new long[2][2];

        res[0][0] = ((lhs[0][0]*rhs[0][0])%p + (lhs[0][1]*rhs[1][0])%p)%p;
        res[1][0] = ((lhs[1][0]*rhs[0][0])%p + (lhs[1][1]*rhs[1][0])%p)%p;
        res[0][1] = ((lhs[0][0]*rhs[0][1])%p + (lhs[0][1]*rhs[1][1])%p)%p;
        res[1][1] = ((lhs[1][0]*rhs[0][1])%p + (lhs[1][1]*rhs[1][1])%p)%p;

        return res;
    }

    // calculate matrix-vector product of a 2x2 matrix and a 2x1 vector
    static long[] matVecProd(long[][] mat, long[] vec) {
        long[] res = new long[2];

        res[0] = ((mat[0][0]*vec[0]) % p + (mat[0][1]*vec[1]) % p) % p;
        res[1] = ((mat[1][0]*vec[0]) % p + (mat[1][1]*vec[1]) % p) % p;

        return res;
    }
}
