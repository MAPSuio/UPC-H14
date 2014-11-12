from sys import stdin

n, o, t, f = map(int, stdin.next().split())

assert(2 <= n <= 500)
assert(0 <= o <= n)
assert(0 <= t <= n)
assert(0 <= o + t <= n)

oslo = {}
os = map(int, stdin.next().split())

assert(len(os) == o)

for i in os:
    assert(1 <= i <= n)
    assert(i not in oslo)

    oslo[i] = True

trondheim = {}
tr = map(int, stdin.next().split())

assert(len(tr) == t)

for i in tr:
    assert(1 <= i <= n)
    assert(i not in oslo)
    assert(i not in trondheim)

    trondheim[i] = True

friends = [[False]*n for i in xrange(n)]
edges = []

if f > 0:
    edges = [map(int, line.split()) for line in stdin]

assert(len(edges) == f)

for e in edges:
    assert(1 <= e[0] <= n)
    assert(1 <= e[1] <= n)
    assert(e[0] < e[1])
    assert(friends[e[0]-1][e[1]-1] == False)

    friends[e[0]-1][e[1]-1] = True

print 'verified'
