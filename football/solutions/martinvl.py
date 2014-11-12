# @EXPECTED_RESULTS@: CORRECT

from sys import stdin
from Queue import Queue

beat = {}
num_beat_by = {}

for line in stdin:
    lhs, mode, rhs = line.split()

    if mode == 'AFTER':
        tmp = lhs
        lhs = rhs
        rhs = tmp

    if not lhs in beat:
        beat[lhs] = []
        num_beat_by[lhs] = 0

    if not rhs in beat:
        beat[rhs] = []
        num_beat_by[rhs] = 0

    beat[lhs].append(rhs)
    num_beat_by[rhs] += 1

q = Queue()

for i in beat:
    if not num_beat_by[i]:
        q.put(i)

order = []

while not q.empty():
    team = q.get()
    order.append(team)

    for b in beat[team]:
        num_beat_by[b] -= 1

        if not num_beat_by[b]:
            q.put(b)

print '\n'.join(order)
