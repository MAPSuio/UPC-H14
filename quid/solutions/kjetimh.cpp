/**
 * Solution to quad by Matias Holte (kjetimh@ulrik.uio.no). Very much inspired
 * by (copied from) http://backtrack-it.blogspot.no/2013/03/max-flow-algorithm-with-sample-c-code.html
 */
#include<cstdio>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
 
#define MAX_NODES 1000  // the maximum number of nodes in the graph
#define INF 2147483646  // represents infity
#define UNINITIALIZED -1 // value for node with no parent
 
using namespace std;
 
// represents the capacities of the edges
int capacities[MAX_NODES][MAX_NODES];
// shows how much flow has passed through an edge
int flowPassed[MAX_NODES][MAX_NODES];
// represents the graph. The graph must contain the negative edges too!
vector<int> graph[MAX_NODES];
// shows the parents of the nodes of the path built by the BFS  
int parentsList[MAX_NODES];      
// shows the maximum flow to a node in the path built by the BFS
int currentPathCapacity[MAX_NODES]; 
 
int bfs(int startNode, int endNode)
{
  memset(parentsList, UNINITIALIZED, sizeof(parentsList));
  memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
 
  queue<int> q;
  q.push(startNode);
  
  parentsList[startNode]=-2;
  currentPathCapacity[startNode]=INF;
 
  while(!q.empty())
    {
      int currentNode = q.front(); q.pop();
 
      for(int i=0; i<graph[currentNode].size(); i++)
	{
	  int to = graph[currentNode][i];
	  if(parentsList[to] == UNINITIALIZED)
	    {
	      if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
		{
		  // we update the parent of the future node to be the current node
		  parentsList[to] = currentNode;
 
		  // we check which is the minimum residual edge capacity so far
		  currentPathCapacity[to] = min(currentPathCapacity[currentNode],
						capacities[currentNode][to] - flowPassed[currentNode][to]);
     
		  // if we have reached the end node the bfs should terminate
		  if(to == endNode) return currentPathCapacity[endNode];
 
		  // we add our future node to the queue
		  q.push(to);
		  }
	      }
	  }
      }
 
  return 0;
}
 
int edmondsKarp(int startNode, int endNode)
{
  int maxFlow=0;
  
  while(true)
    {
      // we find an augmented path and the maximum flow corresponding to it
      int flow=bfs(startNode, endNode);
   
      // if we can't find anymore paths the flow will be 0
      if(flow==0)
	{
	  break;
	  }
 
      maxFlow +=flow;
      int currentNode=endNode;
   
      // we update the passed flow matrix
      while(currentNode != startNode)
	{
	  int previousNode = parentsList[currentNode];
	  flowPassed[previousNode][currentNode] += flow;
	  flowPassed[currentNode][previousNode] -= flow;
 
	  currentNode=previousNode;
	  }
      }
 
  return maxFlow;
}
 
int main()
{
  int nodesCount, trondheim, oslo, edgesCount;
  cin>>nodesCount>>trondheim>>oslo>>edgesCount;

  nodesCount +=2;
  int source=0, sink=nodesCount-1;
  
  for (int i=0; i<trondheim; i++) {
    int decidedForTrondheim;
    cin>>decidedForTrondheim;
    capacities[0][decidedForTrondheim]=INF/10;
    graph[0].push_back(decidedForTrondheim);
    graph[decidedForTrondheim].push_back(0);
  }
  for (int i=0; i<oslo; i++) {
    int decidedForOslo;
    cin>>decidedForOslo;
    capacities[decidedForOslo][sink]=INF/10;
    graph[sink].push_back(decidedForOslo);
    graph[decidedForOslo].push_back(sink);
  }

 
  for(int edge=0; edge<edgesCount; edge++)
    {
      int from, to;
      cin>>from>>to;
 
      capacities[from][to]=1;
      capacities[to][from]=1;
      graph[from].push_back(to);
      //adding the negative edge
      graph[to].push_back(from);
      }
 
  int maxFlow = edmondsKarp(source, sink);
 
  cout<<maxFlow<<endl;
 
  return 0;
}
