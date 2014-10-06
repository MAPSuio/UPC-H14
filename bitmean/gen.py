from numpy.random import randint

K = 10000000
j = randint(1, K)
g = K

print j, g
print '1' + ''.join(map(str, randint(0, 2, j-1).tolist()))
print '1' + ''.join(map(str, randint(0, 2, g-j-1).tolist()) + ['0']*j)
