/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class martinvl_buffered {
    public static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;

    public static String nextLine() throws IOException {
        return stdin.readLine();
    }

    public static String nextToken() throws IOException {
        while(st == null || !st.hasMoreTokens())
            st = new StringTokenizer(nextLine());

        return st.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) throws Exception {
        int n = nextInt();
        double[][] coords = new double[n][2];

        for (int i = 0; i < n; ++i) {
            coords[i][0] = nextDouble();
            coords[i][1] = nextDouble();
        }

        double A = 0;

        for (int i = 0; i < n; ++i) {
            A += coords[i][0]*coords[(i+1)%n][1] - coords[(i+1)%n][0]*coords[i][1];
        }

        A = A < 0 ? -A : A;

        System.out.println(.5*A);
    }
}
