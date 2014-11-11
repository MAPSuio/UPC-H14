# Kristiansand road work
![](../images/kristian.png)

The city of Kristiansand was founded by Christian IV of Denmark-Norway in 1641.
In the interest of order, King Christian constructed the city as a quadrature,
such that the streets form a perfect regular grid. Since all blocks have the
same size, navigating Kristiansand is simple; as long as you never move in the
wrong direction along the x- or y-axis, you will follow a route which is as
short as possible.

![](../images/kristian_map.png)

As a result of this sweet layout, the inhabitants of Kristiansand have no idea
how to navigate a road network that is not a perfect grid. Lately this has
become a problem, as frequently some intersections are closed due to
maintenance. Needless to say, you cannot drive via an intersection that is
closed.

Help the inhabitants of Kristiansand out finding the shortest possible route
they have to drive between a given pair of intersections in the city.

## Input
The first line of input consists of two integers _X_, _Y_ the size of the city
grid.

Then follows _Y_ lines, each with _X_ characters, representing the city grid.
There will be exactly one `S` and exactly one `G` in the grid, denoting the
start and the goal of the route. The rest of the grid will contain either a `+`
or an `X`, indicating that the intersection in that position is opened or
closed, respectively.

## Output
Output the lowest possible number of intersections you have to drive _through_
in order to get from `S` to `G`. If there is no such route, simply output `STAY
WHERE YOU ARE`.

## Constraints
2 &le; _X_, _Y_ &le; 500

## Sample input 1
```
8 8
++++++++
++++++++
++++++++
++S+++++
++XXXX++
++++G+++
++++++++
++++++++
```

## Sample output 1
```
5
```

## Sample input 2
```
8 8
++++++++
++++S+++
++++++++
++++++++
++++X+++
+++XGX++
++++X+++
++++++++
```

## Sample output 2
```
STAY WHERE YOU ARE
```
