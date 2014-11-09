from sys import stdin
from heapq import heapify, heappush, heappop

n, d = map(int, stdin.next().split())
q = map(int, stdin.next().split())
q2 = [map(int, line.split()) for line in stdin]
heapify(q)
heapify(q2)

num_ministers = 0
day = 0

while q or q2:
    if not q:
        day = q2[0][0]

    while q2 and day >= q2[0][0]:
        heappush(q, sum(heappop(q2)))
        continue

    if heappop(q) < day:
        num_ministers += 1

    day += 1

print num_ministers
