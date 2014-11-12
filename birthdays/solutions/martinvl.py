# @EXPECTED_RESULTS@: CORRECT

from datetime import date
from sys import stdin

start, end = [date(*map(int, s.split()[::-1])) for s in stdin.next().split(' - ')]

def is_good_year(year):
    try:
        return date(year, 2, 29).isoweekday() in (5, 6)
    except ValueError:
        return False

print (start < date(start.year, 3, 1) and is_good_year(start.year)) + \
        sum(map(is_good_year, xrange(start.year+1, end.year))) + \
        (end > date(end.year, 2, 28) and is_good_year(end.year))
