#include<iostream>
#include<list>
#include<stack>
#include<algorithm>
#define min(a,b) (a<b)?a:b
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	list<int>::iterator it;
	void DFSUtil(bool visited[],int s);
	void APUtil(int u,bool visited[],bool ap[],int disc[],int low[],int parent[]);
	void isBCUtil(int u,bool visited[],int disc[],int low[],int parent[]);
	bool isConnected();
	public:
		Graph(int V){
			this->V=V;
			adj=new list<int>[V];
		}
		~Graph()
		{
			delete[] adj;
		}
		void addEdge(int u,int v,bool type)
		{
			adj[u].push_back(v);
			if(type)
				adj[v].push_back(u);
		}
		Graph getTranspose();
		bool isBC();
		bool isSC();
		void AP();
		int Eulier_type();
};
void Graph::DFSUtil(bool *visited,int s)
{
	visited[s]=true;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(visited[*it]==false)
			DFSUtil(visited,*it);
	}
}
Graph Graph::getTranspose()
{
	Graph g(V);
	for(int i=0;i<V;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			g.adj[*it].push_back(i);
		}
	}
	return g;
}
bool Graph::isSC()
{
	bool *visited=new bool[this->V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(visited,0);
	for(int i=0;i<this->V;i++)
	{
		if(visited[i]!=true)
			return false;
		else
			visited[i]=false;
	}	
	Graph gr=this->getTranspose();
	gr.DFSUtil(visited,0);
	for(int i=0;i,this->V;i++)
	{
		if(visited[i]!=true)
			return false;
	}
	return true;
}
// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[], 
                                  int low[], int parent[])
{
    // A static variable is used for simplicity, we can 
    // avoid use of static variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
 
            // Check if the subtree rooted with v has a 
            // connection to one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree 
            // under v is  below u in DFS tree, then u-v 
            // is a bridge
            if (low[v] > disc[u])
              cout << u <<" " << v << endl;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// DFS based function to find all bridges. It uses recursive 
// function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
// A recursive function that returns true if there is an articulation
// point in given graph, otherwise returns false.
// This function is almost same as isAPUtil() here ( http://goo.gl/Me9Fw )
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
bool Graph::isBCUtil(int u, bool visited[], int disc[],int low[],int parent[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
 
            // check if subgraph rooted with v has an articulation point
            if (isBCUtil(v, visited, disc, low, parent))
               return true;
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               return true;
 
            // (2) If u is not root and low value of one of its child is
            // more than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               return true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
    return false;
}
 
// The main function that returns true if graph is Biconnected, 
// otherwise false. It uses recursive function isBCUtil()
bool Graph::isBC()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited, and ap(articulation point) 
    //  arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find if there is an articulation 
    // point in given graph. We do DFS traversal starring from vertex 0
    if (isBCUtil(0, visited, disc, low, parent) == true)
        return false;
 
    // Now check whether the given graph is connected or not. An undirected
    // graph is connected if all vertices are reachable from any starting 
    // point (we have taken 0 as starting point)
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
 
    return true;
}
//Function to check if a graph is connected or not
bool Graph::isConnected()
{
	if(i==V)
		return true;
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	for(int i=0;i<V;i++)
		if(adj[i].size()>0)
			break;
	DFSUtil(visited,i);
	for(int i=0;i<V;i++)
		if(!visited[i] && adj[i].size()>0)
			return false;
	return true;
}
//Returns 0->Not a Eulier Graph, 1->Eulier path, 2->Eulier cycle
int Graph::Eulier_type()
{
	int odd=0;
	if(!isConnected())
		return 0;
	for(int i=0;i<V;i++)
	{
		if(adj[i].size() & 1)
			odd++;
	}
	if(odd>2)
		return 0;
	return odd?1:2;
}
void Graph::APUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[])
{
	static int time=0;
	int child=0;
	visited[u]=true;
	disc[u]=low[u]=time++;
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		int v=*i;
		if(!visited[v])
		{
			child++;
			parent[v]=u;
			APUtil(u,visited,disc,low,parent,ap);
			low[u]=min(low[v],low[u]);
			if(parent[u]==-1 && child>1)
				ap[u]=true;
			if(parent[u]!=-1 && low[v]>=disc[u])
				ap[u]=true;
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);
			
	}
}
void Graph::AP()
{
	bool *visited=new bool[V];
	bool *ap=new bool[V];
	int *disc=new int[V];
	int *low=new int[V];
	int *parent=new int[V];
	for(int i=0;i<V;i++)
	{
		parent[i]=-1;
		visited[i]=ap[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			APUtil(i,visited,disc,low,parent,ap);
	}
	for(int i=0;i<V;i++)
	{
		if(ap[i]==true)
			cout<<i<<" ";
	}
}
int main()
{
    // Create graphs given in the above diagrams
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}
