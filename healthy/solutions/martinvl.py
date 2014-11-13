# @EXPECTED_RESULTS@: CORRECT

from sys import stdin
from heapq import heapify, heappush, heappop

n, d = map(int, stdin.next().split())
q, q2 = [], []

if n:
    q = map(int, stdin.next().split())
    heapify(q)

if d:
    q2 = [map(int, line.split()) for line in stdin]
    heapify(q2)

num_ministers = 0
day = 0

while q or q2:
    if not q:
        day = q2[0][0]

    while q2 and day >= q2[0][0]:
        heappush(q, sum(heappop(q2)))
        continue

    resigned = False

    if heappop(q)-1 < day:
        resigned = True

    while q and q[0]-1 <= day:
        resigned = True
        heappop(q)

    if resigned:
        num_ministers += 1

    day += 1

print num_ministers
