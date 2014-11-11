# Roundabout madness
![](<path to image here>)

Nobody knows why there seems to be so much more matter in the universe than
anti-matter.  That does not matter for this problem, but you are a little
concerned for the traffic security in a roundabout nearby.  The roundabout is
very large, which is well, but it is somewhat problematic that there is no
agreement on which direction to drive around it.  Even worse, since right-hand
drivers and left-hand drivers are anti-drivers, they will annihilate each other
when they collide.  The annihilation process will result in a short outburst of
turn light which will not affect the other drivers at all.

You would like to know what the result of the present configuration of cars
will be if they decide to drive around the roundabout until at most one type of
driver is left.

## Input
One string of characters either L or R signifying a driver on his way to the
left or right. The roundabout is cyclic.

## Output
One line of space separated integers denoting the positions (counting from 0)
in the string of the surviving drivers.  The answer should be in ascending
order. If no drivers survive, output a line with the string `Too bad` instead.

## Constraints
The string will contain between 1 and 100 000 characters.

## Sample input
```
LLLRLLR
```

## Sample output
```
1 2 5
```
