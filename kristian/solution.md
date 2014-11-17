# Kristiansand road work
Once the map has been parsed, this problem can be solved using simple [Breadth-first
search](http://en.wikipedia.org/wiki/Breadth-first_search).

Add the starting position to a queue and mark it as visited.

While the queue is not empty;
    - Take out the next position from the queue, add all unvisited neighboring
    positions to the queue, store the distance from the start position
    - Stop searching if G is encountered

When the search stops, one of two things has happened:
- We encountered G, which means that we've found the shortest path
- Have haven't encountered G, which means that it is impossible to find a route
