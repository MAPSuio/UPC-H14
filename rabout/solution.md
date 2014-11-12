# Roundabout madness

This problem can be solved in linear time.  
The first thing to do is to check whether the right drivers or left drivers are
in majority.  

If there are as many L's as R's in the input, everybody will eventually be
annihilated and we output "too bad".  

If there are more R's than L's, then we are interested in the places with
surviving right drivers.  The left drivers will not survive, so we don't need
to keep track of their positions.  Therefore, in the solution, we can start at
some point in the roundabout and move to the left, bringing along left drivers.
Every time we get to an L, we increase the number of left drivers we have by
one.  If we get to a right driver and we have at least one left driver with
us, then the right driver is annihilated and we decrease the number of left
drivers by one.  when we have picked up all the left drivers and annihilated
them with right drivers, we are done and we output the positions with surviving
right drivers.

If there are more L's than R's, we do it the other way around, moving the right
drivers to the right.
