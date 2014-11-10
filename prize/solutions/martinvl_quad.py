# @EXPECTED_RESULTS@: TIMELIMIT

from sys import stdin

n = int(stdin.next())
prizes = [5790] + [float(line.split()[1]) for line in stdin]

# sort prizes, slowly
for i in xrange(n-1):
    for j in xrange(i+1, n-1):
        if prizes[i] < prizes[j]:
            tmp = prizes[i]
            prizes[i] = prizes[j]
            prizes[j] = tmp

p = prizes.index(5790)

if p:
    print p + 1
else:
    print 'STEAL THE PHONE'
