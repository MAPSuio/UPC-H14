# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

stdin.next()

# count the number of prizes that are more valuable than the iphone
more_valuable = sum((float(line.split()[1]) > 5790 for line in stdin))

if more_valuable:
    print more_valuable + 1
else:
    print 'STEAL THE PHONE'
