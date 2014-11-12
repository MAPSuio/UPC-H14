from sys import stdin

m = int(stdin.next())
edge = [[f > 0 for f in map(int, line.split())] for line in stdin]

for i in xrange(m):
    for j in xrange(m):
        edge[i][j] = edge[i][j] or edge[j][i]

edges = []

for i in xrange(m):
    for j in xrange(i+1, m):
        if edge[i][j]:
            edges.append('%d %d' % (i+1, j+1))

print m, 0, 0, len(edges)
print '\n'.join(edges)
