from sys import stdin

print 'no' if stdin.read().strip() == 'yes' else 'yes'
