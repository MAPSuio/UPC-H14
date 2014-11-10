# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()

p = sorted((float(line.split()[1]) for line in stdin), reverse=True).index(5790)

if p:
    print p + 1
else:
    print 'STEAL THE PHONE'
