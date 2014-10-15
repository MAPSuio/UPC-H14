#!/usr/bin/env python
from sys import stdin

temp = 0
prev = 0
curr = 1

fibNumber = int(stdin.readline())

if fibNumber == 0: 
    print prev
elif fibNumber == 1:
    print curr

for i in range(2, fibNumber + 1):
    temp = curr
    curr = curr + prev
    prev = temp

print curr
