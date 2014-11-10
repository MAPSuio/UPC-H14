#  I'd rather walk alone
The solution is to consider each team as an vertex in a graph with the placement constraints as directed edges. 
You can then use topological sorting such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

## Algorithm
First start with all teams that has no incoming edges(which means they should be sorted first). Sort them alphabetically.
Then remove their outgoing edges and if the destination vertex now has 0 incoming edges, add them to a temporary list.
When the first iteration is completed, add them to the result list. Then sort the temporary nodes and repeat the process.
Continue until all edges has been explored and removed.