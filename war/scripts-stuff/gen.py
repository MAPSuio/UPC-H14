#!/usr/bin/python
# Generates random testcases
from random import shuffle

unique=20000
times =5
split =50000

stack = range(0,unique)*times

shuffle(stack)

p1 = []
p2 = []

for i in xrange(0, len(stack)):
    if i < split:
        # player1
        p1.append(stack[i])
    else:
        # player2
        p2.append(stack[i])

print len(p1)
print len(p2)
print " ".join([str(x) for x in p1])
print " ".join([str(x) for x in p2])
