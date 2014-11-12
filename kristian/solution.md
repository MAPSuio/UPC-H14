# Kristiansand road work

A good solution to this problem is to do a breadth first search from both S and G.
This is done by adding S and G to a FIFO queue, and then processing the queue one element at a time.

When the searches intersects, you have a solution. When the queue runs empty without any solutions, there is no solution.

This was implemented by counting up from 0 from S, so that S's neighbors were marked as 1, and the neighbors of 1 are 2.
The same way, this implementation counted down from G, so that G's neighbors were -1, and the neighbors of -1 were -2.
When trying to mark a call, first checking the cell's value will give you information on three scenarios:
* 0: Never visited before, mark this and add it to the queue
* same as your sign: You have already visited it earlier. By the nature of the search, the fastest way is already found, so ignore this
* Opposite sign: The search has intersected, so return the sum of the absolute value of the cell, and the absolute value that you would mark it as if it was 0, minus one. With this, the search is over.

Before you do the search, make sure to return 0 in the case that S and G are neighbors.
