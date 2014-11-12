# @EXPECTED_RESULTS@: CORRECT

from sys import stdin, exit
from collections import deque

n, m = int(stdin.next()), int(stdin.next())
you = deque(map(int, stdin.next().split())) if n else []
mike = deque(map(int, stdin.next().split())) if m else []

you_table = []
mike_table = []

def draw():
    global you, mike, you_table, mike_table

    if not you or not mike:
        if not you and not mike:
            print 'draw'
            exit(0)
        elif not you:
            print 'mike'
            exit(0)
        else:
            print 'you'
            exit(0)

    you_table.append(you.popleft())
    mike_table.append(mike.popleft())

    return you_table[-1], mike_table[-1]

for i in xrange(int(1e5)):
    y, m = draw()

    if y < m:
        for k in mike_table:
            mike.append(k)

        for k in you_table:
            mike.append(k)

        you_table, mike_table  = [], []
    elif y > m:
        for k in you_table:
            you.append(k)

        for k in mike_table:
            you.append(k)

        you_table, mike_table  = [], []
    else:
        for i in xrange(3):
            draw()

print 'draw'
