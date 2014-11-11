/*
@EXPECTED_RESULTS@: TIMELIMIT
*/

import java.util.LinkedList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class martinvl_slow {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int d = in.nextInt();

        LinkedList<Integer> q = new LinkedList<Integer>();

        for (int i = 0; i < n; ++i) {
            q.add(in.nextInt());
        }

        Collections.sort(q);
        LinkedList<int[]> q2 = new LinkedList<int[]>();

        for (int i = 0; i < d; ++i) {
            q2.add(new int[]{in.nextInt(), in.nextInt()});
        }

        Collections.sort(q2, new Comparator<int[]>() {
            public int compare(int[] lhs, int[] rhs) {
                return lhs[0] - rhs[0];
            }
        });

        int numMinisters = 0;

        for (int day = 0; !q.isEmpty() || !q2.isEmpty(); ++day) {
            if (q.isEmpty()) {
                day = q2.peek()[0];
            }

            boolean addedPatients = false;

            while (!q2.isEmpty() && day >= q2.peek()[0]) {
                int[] p = q2.poll();
                q.add(p[0] + p[1]);
                addedPatients = true;
            }

            if (addedPatients) {
                Collections.sort(q);
            }

            boolean resigned = false;

            if (q.poll()-1 < day) {
                resigned = true;
            }

            while (!q.isEmpty() && q.peek()-1 <= day) {
                resigned = true;
                q.poll();
            }

            if (resigned) {
                ++numMinisters;
            }
        }

        System.out.println(numMinisters);
    }
}
