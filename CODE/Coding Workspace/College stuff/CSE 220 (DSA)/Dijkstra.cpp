/*input
5 5
1 2 3
2 5 5
1 5 4
1 3 2
3 4 3
1
*/

//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E(log(V)))

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF INT_MAX //Infinity

const int sz=10000; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<int,int> > a[sz];//Adjacency list
int dis[sz];//Stores shortest distance
bool vis[sz]={0};//Determines whether the node has been visited or not

class comparator //Determines priority for priority queue (shortest edge comes first)
{
public:
	bool operator()(pair<int,int> &a1, pair<int,int> &a2)
	{
		a1.second>a2.second; //sorting on basis of edge weights
	}
};

void Dijkstra(int source, int n) //Algorithm for SSSP 
{
	for(int i=0;i<sz;i++) //Set initial distances to Infinity
		dis[i]=INF;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,comparator> pq; //Priority queue to store vertex,weight pairs
	pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
	while(!pq.empty())
	{
		pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
		pq.pop();
		int cv=curr.first,cw=curr.second;
		vis[cv]=true; //This is the final shortest distance
		for(int i=0;i<a[cv].size();i++) //Iterating through all adjacent vertices
			if(!vis[a[cv][i].first]) //If this vertex is not visited, that means
				if(a[cv][i].second+cw<dis[a[cv][i].first]) //If current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
					pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw))); //Set the new distance and add to priority queue
	}
	cout<<"Source is: "<<source<<". The shortest distance to every other vertex from here is: \n";
	for(int i=1;i<=n;i++)//Printing final shortest distances from source
	{
		cout<<"Vertex: "<<i<<" , Distance: ";
		if(dis[i]!=INF)
			cout<<dis[i]<<endl;
		else
			cout<<"-1\n";
	}
}

int main() //Driver Function for Dijkstra SSSP
{
	int n,m,x,y,w;//Number of vertices and edges
	//cout<<"Enter number of vertices and edges in the graph\n";
	cin>>n>>m;
	for(int i=0;i<m;i++) //Building Graph
	{
		cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
		a[x].push_back(make_pair(y,w));
		a[y].push_back(make_pair(x,w));
	}
	//cout<<"Enter source for Dijkstra's SSSP algorithm\n";
	int source;
	cin>>source;
	Dijkstra(source,n);//SSSP from source (Also passing number of vertices as parameter)
	return 0;
}