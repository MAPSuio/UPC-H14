#!/usr/bin/python

from __future__ import print_function
import random
import hashlib
import sys

def warning(*objs):
    print("WARNING: ", *objs, file=sys.stderr)


def md5(obj):
    m = hashlib.md5()
    m.update(str(obj)+"seedjiasjdlk33!!!")
    return m.hexdigest()

N=100000
place=random.randrange(1,N+1)
target=5790.0

out = []

for i in xrange(1,N+1):
    val = ((place-i)-0.5)*0.001 + target
    out.append([md5(val), val])

warning("Place: "+str(place))

print(len(out))

for o in out:
    print(o[0]+" "+str(o[1]))
