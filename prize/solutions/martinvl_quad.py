# @EXPECTED_RESULTS@: TIMEOUT

from sys import stdin

n = int(stdin.next())
prizes = []
iphone = ()

for line in stdin:
    name, value = line.split()
    record = [float(value), name]

    if name == 'iPhone':
        iphone = record

    prizes.append(record)

# sort prizes, slowly
for i in xrange(n):
    for j in xrange(i+1, n):
        if prizes[i][0] < prizes[j][0]:
            tmp = prizes[i]
            prizes[i] = prizes[j]
            prizes[j] = tmp

p = prizes.index(iphone)

if p:
    print p + 1
else:
    print 'STEAL THE PHONE'
