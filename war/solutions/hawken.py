# @EXPECTED_RESULTS@: CORRECT

from collections import deque
from sys import stdin

# Read
n = int(stdin.next().strip())
m = int(stdin.next().strip())

p1stack = deque()
p2stack = deque()

p1bet = deque()
p2bet = deque()

p1card = None
p2card = None

if n:
    line = stdin.next()
    [p1stack.append(int(x)) for x in line.strip().split()]
if m:
    line = stdin.next()
    [p2stack.append(int(x)) for x in line.strip().split()]
iter = 0
while len(p1stack) and len(p2stack):
    p1card = p1stack.popleft()
    p2card = p2stack.popleft()
    if p1card == p2card:
        # Put their current cards as bet
        p1bet.append(p1card)
        p2bet.append(p2card)
        # Put three new as bet
        for i in xrange(0,3):
            if not len(p1stack) or not len(p2stack):
                break
            p1bet.append(p1stack.popleft())
            p2bet.append(p2stack.popleft())
    elif p1card > p2card:
        while len(p1bet):
            p1stack.append(p1bet.popleft())

        p1stack.append(p1card)

        while len(p2bet):
            p1stack.append(p2bet.popleft())

        p1stack.append(p2card)
    else:
        while len(p2bet):
            p2stack.append(p2bet.popleft())

        p2stack.append(p2card)

        while len(p1bet):
            p2stack.append(p1bet.popleft())

        p2stack.append(p1card)
    iter = iter + 1
    if iter == 100000:
        break

if (not len(p1stack) and not len (p2stack)) or iter >= 100000:
    print "draw"
elif not len(p1stack):
    print "mike"
else:
    print "you"
