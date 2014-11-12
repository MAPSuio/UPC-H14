from math import cos, sin, pi
n = int(1e4)

r = (1, 2, 1, 1, 3)

print n

for i in xrange(n):
    t = i*2*pi/n

    print '%.8f %.8f' % (r[i % len(r)]*cos(t), r[i % len(r)]*sin(t))
