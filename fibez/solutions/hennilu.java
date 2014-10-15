import java.util.Scanner;
import java.math.BigInteger;

public class hennilu {
    public static void main(String[] args) {
        BigInteger prev = new BigInteger("0");
        BigInteger curr = new BigInteger("1");
        BigInteger temp;

        try {
            int fibNumber = new Scanner(System.in).nextInt();

            if (fibNumber == 0) {
                System.out.println(prev);
                return;
            } else if (fibNumber == 1) {
                System.out.println(curr);
                return;
            }

            for (int i = 2; i <= fibNumber; i++) {
                temp = curr;
                curr = curr.add(prev);
                prev = temp;
            }
            System.out.println(curr);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
