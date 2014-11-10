# A bit mean
![](../images/bitmean.jpg)

A friend of yours, suitably nicknamed Average Joe, is known for annoying
everyone around by posing silly questions such as; "What is the average of the
30 first Fibonacci numbers?" or "What is the average of the primes smaller than
1 million?".

Lately Joe's been posing questions about averaging binary numbers, which is
even more annoying. Not only that; he demands you answer them in binary as
well!  Needless to say; you've had enough of wasting time on Joe's questions,
and decided to write a program that can answer these questions
automatically.

It turns out there is a pattern in Joe's questions; he's always asking for the
average of two binary numbers, where the first number has _n_ binary digits,
and the second number always is a multiple of 2<sup>n</sup>. Since the
numbers are binary, Joe doesn't care for decimals, so just round the
answer down to the nearest integer.

## Input
The first line of input contains two integers _n_ and _m_, the number of binary
digits in the two numbers respectively.

Then follows two lines containing the two binary numbers.

You can assume none of the numbers will be 0.

## Output
Output the mean of the to binary numbers. The answer must also be formatted in
binary.

## Constraints
1 &le; _n_ < _m_ &le; 10<sup>7</sup>

## Sample input
```
4 8
1101
10110000
```

## Sample output
```
1011110
```
