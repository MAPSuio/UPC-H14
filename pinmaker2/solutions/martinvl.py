# @EXPECTED_RESULTS@: CORRECT

from sys import stdin

p = int(1e8)

# calculate matrix product of two 2x2 matrices
def mat_prod(lhs, rhs):
    res = [[0, 0], [0, 0]]

    res[0][0] = (lhs[0][0]*rhs[0][0] + lhs[0][1]*rhs[1][0]) % p
    res[1][0] = (lhs[1][0]*rhs[0][0] + lhs[1][1]*rhs[1][0]) % p
    res[0][1] = (lhs[0][0]*rhs[0][1] + lhs[0][1]*rhs[1][1]) % p
    res[1][1] = (lhs[1][0]*rhs[0][1] + lhs[1][1]*rhs[1][1]) % p

    return res

# calculate matrix-vector product of a 2x2 matrix and a 2x1 vector
def mat_vec_prod(mat, vec):
    res = [0, 0]

    res[0] = (mat[0][0]*vec[0] + mat[0][1]*vec[1]) % p
    res[1] = (mat[1][0]*vec[0] + mat[1][1]*vec[1]) % p

    return res

# calculate mat^n for 2x2 matrix, n >= 1
def mat_exp(mat, n):
    res = [[1, 0], [0, 1]]

    while n:
        if n % 2:
            res = mat_prod(res, mat)

        mat = mat_prod(mat, mat)
        n /= 2

    return res

def keanucci(d, m, n):
    if n == 0:
        return d

    if n == 1:
        return m

    mat = [[1, 1], [1, 0]]
    vec = [m, d]

    return mat_vec_prod(mat_exp(mat, n-1), vec)[0]

d, m, n = map(int, stdin.read().split())
print '%08d' % (keanucci(d, m, n) % p)
