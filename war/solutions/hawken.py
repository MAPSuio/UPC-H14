# @EXPECTED_RESULTS@: CORRECT

from Queue import Queue
from sys import stdin

# Read
n = int(stdin.next().strip())
m = int(stdin.next().strip())

p1stack = Queue()
p2stack = Queue()

p1bet = Queue()
p2bet = Queue()

p1card = None
p2card = None

line = stdin.next()
[p1stack.put(int(x)) for x in line.strip().split()]
line = stdin.next()
[p2stack.put(int(x)) for x in line.strip().split()]

while not p1stack.empty() and not p2stack.empty():
    p1card = p1stack.get()
    p2card = p2stack.get()
    if p1card == p2card:
        # Put their current cards as bet
        p1bet.put(p1card)
        p2bet.put(p2card)
        # Put three new as bet
        for i in xrange(0,3):
            if not p1stack.empty():
                p1bet.put(p1stack.get())
            if not p2stack.empty():
                p2bet.put(p2stack.get())
    elif p1card > p2card:
        while not p1bet.empty():
            p1stack.put(p1bet.get())

        p1stack.put(p1card)

        while not p2bet.empty():
            p1stack.put(p2bet.get())

        p1stack.put(p2card)
    else:
        while not p2bet.empty():
            p2stack.put(p2bet.get())

        p2stack.put(p2card)

        while not p1bet.empty():
            p2stack.put(p1bet.get())

        p2stack.put(p1card)

if p1stack.empty() and p2stack.empty():
    print "draw"
elif p1stack.empty():
    print "PLAYER2"
else:
    print "PLAYER1"
