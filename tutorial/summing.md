# Summing up
You have a lot a text containing ten integers on each line, and you really want to calculate the sum of these ten integers for each line.

Make a program that calculates the sum of the integers on each line.

## Input
The first line of input contains a single integer _n_, the number of integer
lines.

Then follows _n_ lines, each containing 10 integers _i<sub>j</sub>_.

## Output
For each line of input, output the sum of all _i<sub>j</sub>_ on that line.

## Constraints
1 &le; _n_ &le; 10<sup>3</sup>  
0 &le; |_i<sub>j</sub>_| &le; 10<sup>6</sup>

## Sample input 1
```
1
1 1 1 1 1 1 1 1 1 1
```

## Sample output 1
```
10
```

## Sample input 2
```
4
1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2 2
0 1 2 3 4 5 6 7 8 9
-5 -4 -3 -2 -1 1 2 3 4 5
```

## Sample output 2
```
10
20
45
0
```
