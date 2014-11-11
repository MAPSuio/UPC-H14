# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

X, Y, M = map(int, stdin.next().split())

opened = [[True]*Y for i in xrange(X)]

def bfs(start, goal):
    global opened, X, Y
    dist = [[-1]*Y for i in xrange(X)]

    dist[start[0]][start[1]] = 0
    q = [start]

    while q:
        nq = []

        for p in q:
            if p == goal:
                return dist[goal[0]][goal[1]]

            for dp in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                np = (p[0] + dp[0], p[1] + dp[1])

                if np[0] < 0 or np[0] >= X or np[1] < 0 or np[1] >= Y:
                    continue

                if dist[np[0]][np[1]] == -1 and opened[np[0]][np[1]]:
                    dist[np[0]][np[1]] = dist[p[0]][p[1]] + 1
                    nq.append(np)

        q = nq

    return -1

for data in (line.split() for line in stdin):
    if data[0] == 'OPENED' or data[0] == 'CLOSED':
        x, y = map(int, data[1:])
        opened[x][y] = data[0] == 'OPENED'
    else:
        x1, y1, x2, y2 = map(int, data[1:])
        dist = bfs((x1, y1), (x2, y2))

        if dist == -1:
            print 'STAY WHERE YOU ARE'
        else:
            print dist
