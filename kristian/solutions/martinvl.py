# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

N, M = map(int, stdin.next().split())
raw_grid = ''.join(stdin).replace('\n', '')

# find start and goal
start_idx = raw_grid.index('S')
start = (start_idx / N, start_idx % N)

goal_idx = raw_grid.index('G')
goal = (goal_idx / N, goal_idx % N)

# find open intersections
opened = [[c != 'X' for c in raw_grid[i:i+N]] for i in xrange(0, M*N, N)]

def get_neighbors(p):
    global M, N

    for dp in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        np = (p[0] + dp[0], p[1] + dp[1])

        if np[0] < 0 or np[0] >= M or np[1] < 0 or np[1] >= N:
            continue

        yield np

def bfs(start, goal):
    global opened, M, N
    dist = [[-1]*N for i in xrange(M)]

    dist[start[0]][start[1]] = 0
    q = [start]

    while q:
        nq = []

        for p in q:
            if p == goal:
                return dist[goal[0]][goal[1]]

            for np in get_neighbors(p):
                if dist[np[0]][np[1]] == -1 and opened[np[0]][np[1]]:
                    dist[np[0]][np[1]] = dist[p[0]][p[1]] + 1
                    nq.append(np)

        q = nq

    return -1

dist = bfs(start, goal)

if dist == -1:
    print 'STAY WHERE YOU ARE'
else:
    print dist-1
