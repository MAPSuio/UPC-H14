# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()
prizes = []
iphone = ()

for line in stdin:
    name, value = line.split()
    record = (float(value), name)

    if name == 'iPhone':
        iphone = record

    prizes.append(record)

p = sorted(prizes, reverse=True).index(iphone)

if p:
    print p + 1
else:
    print 'STEAL THE PHONE'
