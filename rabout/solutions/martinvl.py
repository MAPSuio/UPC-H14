# @EXPECTED_RESULTS@: CORRECT

from sys import stdin, exit

s = stdin.read().strip()
n = len(s)
num_L = sum((c == 'L' for c in s))
num_R = n - num_L

if num_L == num_R:
    print 'Too Bad'
    exit(0)

alive = [True]*n

if num_R > num_L:
    L = 0

    for i in xrange(2*n, 0, -1):
        i %= n

        if s[i] == 'L':
            if alive[i]:
                L += 1

            alive[i] = False
        elif L > 0 and alive[i]:
            L -= 1
            alive[i] = False


if num_L > num_R:
    R = 0

    for i in xrange(2*n):
        i %= n

        if s[i] == 'R':
            if alive[i]:
                R += 1

            alive[i] = False
        elif R > 0 and alive[i]:
            R -= 1
            alive[i] = False

pos = []

for i in xrange(n):
    if alive[i]:
        pos.append(i)

print ' '.join(map(str, pos))
