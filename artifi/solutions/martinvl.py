# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

print 'no' if stdin.read().strip() == 'yes' else 'yes'
