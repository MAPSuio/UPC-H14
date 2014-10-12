# The pinmaker 2
(See _The pinmaker_ for full introduction)

![](../images/pinmaker.jpg)

It turns out that using the number of days between Keanu's last two electrical bills from BKK as _n_ isn't ideal. Although truly random, this number is rarely larger than 50, which means that the number of possible different PIN-codes is limited. Keanu has therefore come up with a new way of selecting _n_ such that it can be a lot (a _lot_) larger. Other than a larger _n_, Keanu's PIN-code scheme is the same as before.

Can you come up with an algorithm that calculates Keanu's PIN code for such large _n_?

## Input
The input consists of three space separated integers _d_, _m_ and _n_, the current day, month and the random number Keanu came up with.

## Output
Output Keanu's 8 digit PIN-code for the given day.

## Constraints
1 &le; _d_ &le; 31  
1 &le; _m_ &le; 12  
1 &le; _n_ &le; 10<sup>1000</sup>

## Sample input
```
1 1 1000
```

## Sample output
```
23403501
```