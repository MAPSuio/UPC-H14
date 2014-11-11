/*
@EXPECTED_RESULTS@: CORRECT
*/

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Arrays;

public class martinvl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int M = in.nextInt();
        in.nextLine();

        boolean[][] grid = new boolean[M][N];
        int[] start = new int[]{0, 0};
        int[] goal = new int[]{0, 0};

        for (int i = 0; i < M; ++i) {
            char[] part = in.nextLine().toCharArray();

            for (int j = 0; j < N; ++j) {
                grid[i][j] = part[j] != 'X';

                if (part[j] == 'S') {
                    start = new int[]{i, j};
                } else if (part[j] == 'G') {
                    goal = new int[]{i, j};
                }
            }
        }

        int dist = bfs(grid, start, goal);

        if (dist == -1) {
            System.out.println("STAY WHERE YOU ARE");
        } else {
            System.out.println(dist-1);
        }
    }

    static final int[][] DP = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    static int bfs(boolean[][] grid, int[] start, int[] goal) {
        int M = grid.length;
        int N = grid[0].length;
        int[][] dist = new int[M][N];
        LinkedList<int[]> q = new LinkedList<int[]>();

        for (int i = 0; i < M; ++i) {
            Arrays.fill(dist[i], -1);
        }

        dist[start[0]][start[1]] = 0;
        q.add(start);

        while (!q.isEmpty()) {
            int[] p = q.poll();

            if (p[0] == goal[0] && p[1] == goal[1]) {
                break;
            }

            for (int[] dp : DP) {
                int[] np = new int[]{p[0] + dp[0], p[1] + dp[1]};

                if (np[0] < 0 || np[0] >= M || np[1] < 0 || np[1] >= N) {
                    continue;
                }

                if (dist[np[0]][np[1]] != -1 || !grid[np[0]][np[1]]) {
                    continue;
                }

                dist[np[0]][np[1]] = dist[p[0]][p[1]] + 1;
                q.add(np);
            }
        }

        return dist[goal[0]][goal[1]];
    }
}
