# A walk in the park

![](<path to image here>)

Angwusnasomtaqa and Bob are walking their dog Chavatangakwunua.  They are
walking along a long path with trees appearing now and then.  The distances
between the trees are always an integer when measured in metres.   As they move
along,  Chavatangakwunua will always mark the passed trees as his by a process
which is known medically as micturition.  This is nice for him, but there is no
tree at the end of the road, so when they get there he will be confused and
ultimately the person holding the leash at that point will soon feel the urge to
take a shower and put on new clothes.  

Angwusnasomtaqa and Bob have a very peculiar way of alternating who is holding
the leash.  While they are walking, the person holding the leash can walk a
distance of her or his choice of integral length larger than zero (in metres), but never pass
the next tree before handing the leash to the other.  Angwusnasomtaqa holds the
leash first.

Neither wants to be marked. If they play the game optimally, who will win?  The
loser is the person holding the leash at the last meter of the walk.

## Input
The first line of input contains an integer _n_, the number of trees along the
road.  Then follows a line with _n_+1 integers.  The first integer is the
distance from the start to the first tree. The next _n_-1 integers are the
distances in metres between neighbouring trees as they appear along the path.
The last integer is the distance from the last tree to the end of the path.

## Output
One single line with the name of winner.

## Constraints
0<_n_<100000

All the input distances are one digit integers larger than 0.

## Sample input 1
3
5 6 7 8

## Sample output 1
Angwusnasomtaqa

## Sample input 2
2
1 1 1

## Sample output 2
Bob
