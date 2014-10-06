# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()
j = stdin.next().strip()
g = stdin.next().strip()

print g[:-len(j)] + j[:-1]
