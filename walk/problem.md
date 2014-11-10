# Walking the dog

![](<path to image here>)

Angwusnasomtaqa and Bob are walking their dog Chavatangakwunua in a park.  The
park is represented by a graph with sides of prime length.  As they move
around,  Chavatangakwunua will constantly mark the passed paths as his own
territory.  This is all very well, but if he covers a segment of path for the
second time, he will be confused and mark the person holding the leash instead.  

Angwusnasomtaqa and Bob have a very peculiar way of alternating who is holding
the leash. While they are walking from one node to the next, the person holding
the leash can walk a distance of her or his choice of integral length, but
never pass the next node before handing the leash to the other.  When they are
at a node, the person holding the leash decides which path they will follow
from there.  They will always start from the 0th node with Angwusnasomtaqa
holding the leash and they will go home and change to dry clothes as soon as
one of them gets marked by Chavatangakwunua.

Neither wants to be marked, if they play the game optimally, who will win?

## Input
The first line of input contains two integers _n_ and _m_, the number of nodes
in the graph and the number of roads in the park. Then follows _m_ lines, each
line with three numbers _a_, _b_ and _p_, signifying that there is a path from
node _a_ to node _b_ with length _p_.  The nodes are counted from 0 to _n_-1.

## Output
One single line with the name of winner.

## Constraints
1<_n_<100000
0<_m_<200000
p<100000 is a prime number

## Sample input
2 1 0 1 2

## Sample output
Angwusnasomtaqa
