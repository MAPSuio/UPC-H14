# @EXPECTED_RESULTS@: TIMEOUT

from sys import stdin

def keanucci(d, m, n):
    if n == 0:
        return d

    if n == 1:
        return m

    pprev = d
    prev = m

    while n:
        cur = (pprev + prev) % int(1e8)
        pprev = prev
        prev = cur
        n -= 1

    return prev

d, m, n = map(int, stdin.read().split())
print '%08d' % (keanucci(d, m, n) % int(1e8))
