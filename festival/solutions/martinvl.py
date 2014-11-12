# @EXPECTED_RESULTS@: CORRECT

from sys import stdin
from math import atan2

n = int(stdin.next())
coords = [map(float, line.split()) for line in stdin]

A = 0

for i in xrange(n):
    A += coords[i][0]*coords[(i+1)%n][1] - coords[(i+1)%n][0]*coords[i][1]

print .5*abs(A)
