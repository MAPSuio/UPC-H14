# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

# Read
n = int(stdin.next().strip())
m = int(stdin.next().strip())

p1stack = []
p2stack = []

p1bet = []
p2bet = []

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
    p1card = p1stack[0]
    p1stack = p1stack[1:]
    p2card = p2stack[0]
    p2stack = p2stack[1:]
    if p1card == p2card:
        # Put their current cards as bet
        p1bet.append(p1card)
        p2bet.append(p2card)
        # Put three new as bet
        for i in xrange(0,3):
            if len(p1stack):
                v = p1stack[0]
                p1stack = p1stack[1:]
                p1bet.append(v)
            if len(p2stack):
                v = p2stack[0]
                p2stack = p2stack[1:]
                p2bet.append(v)
    elif p1card > p2card:
        while len(p1bet):
            v = p1bet[0]
            p1bet = p1bet[1:]
            p1stack.append(v)

        p1stack.append(p1card)

        while len(p2bet):
            v = p2bet[0]
            p2bet = p2bet[1:]
            p1stack.append(v)

        p1stack.append(p2card)
    else:
        while len(p2bet):
            v = p2bet[0]
            p2bet = p2bet[1:]
            p2stack.append(v)

        p2stack.append(p2card)

        while len(p1bet):
            v = p1bet[0]
            p1bet = p1bet[1:]
            p2stack.append(v)

        p2stack.append(p1card)
    iter = iter + 1

if (not len(p1stack) and not len(p2stack)) or iter >= 100000:
    print "draw"
elif not len(p1stack):
    print "mike"
else:
    print "you"
