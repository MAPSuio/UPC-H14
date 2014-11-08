import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int d = in.nextInt();

        PriorityQueue<Integer> q = new PriorityQueue<Integer>();

        for (int i = 0; i < n; ++i) {
            q.add(in.nextInt());
        }

        PriorityQueue<int[]> q2 = new PriorityQueue<int[]>(d, new Comparator<int[]>() {
            public int compare(int[] lhs, int[] rhs) {
                return lhs[0] - rhs[0];
            }
        });

        for (int i = 0; i < d; ++i) {
            q2.add(new int[]{in.nextInt(), in.nextInt()});
        }

        int numMinisters = 0;

        for (int day = 0; !q.isEmpty() || !q2.isEmpty(); ++day) {
            if (q.isEmpty()) {
                day = q2.peek()[0];
            }

            while (!q2.isEmpty() && day >= q2.peek()[0]) {
                int[] p = q2.poll();
                q.add(p[0] + p[1]);
            }

            if (q.poll() < day) {
                ++numMinisters;
            }
        }

        System.out.println(numMinisters);
    }
}
