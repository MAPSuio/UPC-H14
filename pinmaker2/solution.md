# The pinmaker 2
Input here is way too large for a linear algorithm to finish in time.

Iterating the difference equation one step can be done using matrix-notation
like this:

![](http://latex.codecogs.com/png.latex?\begin{bmatrix}&space;k_{n}&space;\\\\&space;k_{n-1}&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;1&space;&&space;1&space;\\\\&space;1&space;&&space;0&space;\end{bmatrix}&space;\begin{bmatrix}&space;k_{n-1}&space;\\\\&space;k_{n-2}&space;\end{bmatrix})

This can be generalized to _n_:

![](http://latex.codecogs.com/png.latex?\begin{bmatrix}&space;k_{n}&space;\\\\&space;k_{n-1}&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;1&space;&&space;1&space;\\\\&space;1&space;&&space;0&space;\end{bmatrix}^n&space;\begin{bmatrix}&space;k_{1}&space;\\\\&space;k_{0}&space;\end{bmatrix})

Matrix exponentiation can be done in O(log n) using [exponentiation by squaring](http://en.wikipedia.org/wiki/Exponentiation_by_squaring). Remember to do modulo 10<sup>8</sup> after all operations to avoid overflows.