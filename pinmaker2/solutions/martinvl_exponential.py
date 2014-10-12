# @EXPECTED_RESULTS@: TIMEOUT

from sys import stdin

def keanucci(d, m, n):
    if n < 2:
        return m if n else d

    return (keanucci(d, m, n-1) + keanucci(d, m, n-2)) % int(1e8)

d, m, n = map(int, stdin.read().split())
print '%08d' % keanucci(d, m, n)
