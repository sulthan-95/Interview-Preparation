#include<iostream>
#include<algorithm>
struct Edge{
	int src,dest;
};
//Edge based Implementation
struct Graph{
	struct Edge *ed;
	int V,E;
};
Graph *create(int V,int E)
{
	Graph *g=new Graph;
	g->V=V;
	g->E=E;
	g->ed=new Edge[E];
	return g;
}
int find(int *parent,int i)
{
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}
void Union(int *parent,int u,int v)
{
	int us=find(parent,u);
	int vs=find(parent,v);
	parent[us]=vs;
}
bool is_cycle(Graph *g)
{
	int *parent=new int[g->V];
	fill_n(parent,g->V,-1);
	for(int i=0;i<g->E;i++)
	{
		int x=find(parent,g->ed[i].src);
		int y=find(parent,g->ed[i].dest);
		if(x==y)
			return true;
		Union(parent,x,y);
	}
	return false;
}
		
int main()
{
	Graph *g;
      	int V,E,s,d;
	cin>>V; 
        //cout<<"\nEnter the no. of Edges..";
        cin>>E;
	g=create(V,E);
        cout<<"\nEnter the edge verices line by line..";
        for(int i=0;i<E;i++)
        {
                cin>>s>>d;
                g->ed[i].src=s;
		g->ed[i].dest=d;
		//v[d].push_back(s);
        }
        if(is_cycle(g))
		cout<<"There is a cycle in this graph..";
	cout<<endl;
        return 0;
}

