# Festival area
![](../images/festival.png)

Arranging a festival is a lot of work. You have to book artists and
attractions, provide food, sell tickets etc. Another important aspect of
arranging a festival is to put up a fence around the festival area, to ensure
that everybody inside has bought a ticket.

Fences around festival areas typically consist of several straight fences
attached together at a fence post, to form the shape of a polygon. For the
festival planners to be able to calculate the number of tickets they can sell,
it is important to know the area of the festival area. Help the
planners out in finding the area of their planned festival area.

## Input
The first line of input contains an integer _N_, the number of fence posts in
the fence.  

Then follows _N_ lines describing the fence posts. Line _i_ contains two
numbers _x_ and _y_, the coordinates (_x_, _y_) of fence post _i_. The fence
lines are ordered such that fence post _i_ is directly connected to fence post
_i + 1_ and _i - 1_.

## Output
Print the area of the festival area. Solutions with an absolute or relative
error less than 10<sup>-8</sup> will be accepted.

## Constraints
3 &le; _N_ &le; 10<sup>6</sup>

## Sample input 1
```
4
-1 1
1 1
1 -1
-1 -1
```

## Sample output 1
```
4.0
```

## Sample input 2
```
5
-4 9
3 10
6 1
-1 -2
-3 -2
```

## Sample output 2
```
87.0
```
