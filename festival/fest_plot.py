from sys import stdin
from scitools.std import *
from time import sleep

N = int(stdin.next())
x, y = zip(*[map(float, line.split()) for line in stdin])

plot(list(x) + [x[0]], list(y) + [y[0]])
axis([min(x) - 1, max(x) + 1, min(y) - 1, max(y) + 1])
sleep(3000)
