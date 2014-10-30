import java.util.Scanner;

public class martinvl {
    static final int INF = Integer.MAX_VALUE/2;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int o = in.nextInt();
        int t = in.nextInt();
        int f = in.nextInt();

        Graph g = new Graph(n + 2);
        int oslo = 0;
        int trondheim = n + 1;

        // add Oslo lovers
        for (int i = 0; i < o; ++i) {
            g.addEdge(oslo, in.nextInt(), INF);
        }

        // add Trondheim lovers
        for (int i = 0; i < t; ++i) {
            g.addEdge(trondheim, in.nextInt(), INF);
        }

        // add friendships
        for (int i = 0; i < f; ++i) {
            g.addEdge(in.nextInt(), in.nextInt(), 1);
        }

        System.out.println(FFA(g, oslo, trondheim));
    }

    static int FFA(Graph g, int source, int sink) {
        int maxFlow = 0;
        int flow;

        while ((flow = increaseFlow(g, sink, source, INF)) != 0) {
            maxFlow += flow;
        }

        return maxFlow;
    }

    static int increaseFlow(Graph g, int sink, int node, int cap) {
        if (node == sink) {
            return cap;
        }

        for (Edge e = g.edges[node]; e != null; e = e.next) {
            if (e.visited) {
                continue;
            }

            int newCap = Math.min(cap, e.cap - e.flow);

            if (newCap == 0) {
                continue;
            }

            e.visited = true;
            int flow = increaseFlow(g, sink, e.to, newCap);
            e.visited = false;

            if (flow == 0) {
                continue;
            }

            e.flow += flow;
            e.rev.flow -= flow;
            return flow;
        }

        return 0;
    }

    static class Graph {
        Edge[] edges;

        public Graph(int n) {
            edges = new Edge[n];
        }

        public void addEdge(int from, int to, int cap) {
            edges[from] = new Edge(from, to, cap, edges[from]);
            edges[to] = new Edge(to, from, cap, edges[to]);

            edges[from].rev = edges[to];
            edges[to].rev = edges[from];
        }
    }

    static class Edge {
        int from, to, cap, flow;
        Edge rev, next;
        boolean visited;

        public Edge(int from, int to, int cap, Edge next) {
            this.from = from;
            this.to = to;
            this.cap = cap;
            this.next = next;
        }
    }
}
