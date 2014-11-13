import java.util.Scanner;

public class summing {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        for (int i = 0; i < n; ++i) {
            // sum the ten integers
            int sum = 0;

            for (int j = 0; j < 10; ++j) {
                sum += in.nextInt();
            }

            // print the result
            System.out.println(sum);
        }
    }
}
