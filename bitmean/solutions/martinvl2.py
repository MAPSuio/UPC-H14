# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()
j = int(stdin.next(), 2)
g = int(stdin.next(), 2)

print bin((j + g)/2)[2:]
