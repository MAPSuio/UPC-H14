#!/usr/bin/python
# Huge testcase for those who do stupid stuff

from random import randrange

n=99999
ones=201 #Anasdasdwww...


print n

i = 0
out = []
while i < n+1:
    if ones > 0:
        out.append(1)
        ones -= 1
    elif ones == 0:
        out.append(randrange(2, 10))
        ones -= 1
    else:
        out.append(randrange(1, 10))
    i += 1

print " ".join([str(x) for x in out])
