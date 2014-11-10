# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()
prizes = [line.split() for line in stdin]

# find prize of iphone
iphone = 0

for prize in prizes:
    if prize[0] == 'iPhone':
        iphone = float(prize[1])
        break

# count the number of prizes that are more valuable
more_valuable = sum(map(lambda prize: float(prize[1]) > iphone, prizes))

if more_valuable:
    print more_valuable + 1
else:
    print 'STEAL THE PHONE'
