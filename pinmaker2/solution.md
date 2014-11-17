# The pinmaker 2
Input here is way too large for a linear algorithm to finish in time.

Iterating the difference equation one step can be done using matrix-notation
like this:

![](../images/pinmaker2-sol.png)

This can be generalized to _n_:

![](../images/pinmaker2-sol2.png)

Matrix exponentiation can be done in O(log n) using [exponentiation by squaring](http://en.wikipedia.org/wiki/Exponentiation_by_squaring). Remember to do modulo 10<sup>8</sup> after all operations to avoid overflows.