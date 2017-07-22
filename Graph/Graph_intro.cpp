#include<iostream>
#include<list>
#include<stack>
#include<limits.h>
#include<string.h>
#define NINF INT_MIN
using namespace std;
class AdjListNode{
	int v,weight;
	public:
	AdjListNode(int v,int w){
		this->v=v;
		this->weight=w;
	}
	int getv(){ return this->v;	}
	int getweight(){
		return this->weight;
	}
};
class Graph{
	list<AdjListNode> *adj;
	int V;
	bool **tc; // To store transitive closure
	void topological_sorting(bool *visited,int v,stack<int> &S);
	public:
		Graph(int V);
		void add_edge(int u,int v,int w);
		void longest_Path(int s);
		int mother();
		void DFS(bool *visited,int s);
		void tc_DFS(int u,int v);
};
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<AdjListNode>[V];
	tc=new bool*[V];
	for(int i=0;i<V;i++)
	{
		tc[i]=new bool[V];
		memset(tc[i],false,V);
	}
}
void Graph::add_edge(int u,int v,int w)
{
	AdjListNode node(v,w);
	adj[u].push_back(node);
}
void Graph::topological_sorting(bool *visited,int v,stack<int> &S)
{
	visited[v]=true;
	list<AdjListNode>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		AdjListNode node=*i;
		if(!visited[node.getv()])
			topological_sort(visited,node.getv(),S);
	}
	S.push(v);
}
void Graph::longest_path(int s)
{
	int dist[V];
	memset(dist,NINF,V);	
	bool visited[V];
	memset(visited,false,V);
	stack<int> S;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			topological_sort(visited,i,S);
	}
	dist[s]=0;
	while(!S.empty())
	{
		int u=S.top();
		S.pop();
		list<AdjListNode>::iterator i;
		if(dist[u]!=NINF)
		{
			for(i=adj[u].begin();i!=adj[u].end();i++)
			{
				if(dist[i->getv()] < dist[u]+i->getweight())
					dist[i->getv()]=dist[u]+i->getweight();
			}
		}	 
	}
	for(i=0;i<V;i++)
		(dist[i]==NINF)?cout<<"INF ":cout<<dist[i]<<" ";
}
void Graph::DFS(bool *visited,int s)
{
	visited[s]=true;
	list<AdjListNode>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		AdjListNode node=*i;
		if(visited[node.getv()]==false)
			DFS(visited,node.getv());
	}
}
int Graph::mother()
{
	int v;
	bool visited[V];
	memset(visited,false,V);
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFS(visited,i);
			v=i;
		}
	}
	//IF v is the mother vertex..(i.e)vertex from which all other vertex can be reached...
	// then it should be last finished vertex..
	//To check if its mother or not DFS with v as source should reach all
	memset(visited,false,V);
	DFS(visited,v)
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			return -1;
	}
	return v;
}
void Graph::tc_DFS(int u,int v)
{
	tc[u][v]=true;
	list<AdjListNode>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		if(tc[u][i->getv()]==false)
			tc_DFS(u,i->getv());
	}
}
void Graph::transitive_closure()
{
	for(int i=0;i<V;i++)
		tc_DFS(i,i);
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<tc[i][j]?1:0<<" ";
		cout<<endl;
	}
}
int main()
{
	return 0;
}
