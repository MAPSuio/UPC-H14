# A bit mean
Since the second number is a multiple of 2<sup>n</sup>, the _n_ last digits
will be zero. This means that summing the two numbers is the same as replacing
the last _n_ digits of the second number with the digits of the first number.
Dividing by 2 and rounding down is the same as shifting all the bits to the
right, i.e. removing the last digit.

Using `int` or `long` is obviously not possible since the numbers can have way
too many digits. Using `BigInteger` in Java would word, but unfortunately it is
way too slow. Python's `int` handles arbitrarily large numbers efficiently, and
can be used to solve this problem.
