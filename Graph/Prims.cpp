#include <stdio.h>
#include <limits.h>
#define V 5
int minkey(int key[],bool mst[])
{
	int min=INT_MAX,index=0;
	for(int i=0;i<V;i++)
	{
		if(mst[i]==false && key[i]<min)
		{
			min=key[i];
			index=i;
		}
	}
	return index;
}
void printmst(int parent[],int graph[V][V])
{
	for(int i=0;i<V;i++)
		printf("%d->%d %d\n",parent[i],i,graph[i][parent[i]]);
}
void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mst[V];
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		parent[i]=-1;
		mst[i]=false;
	}
	int count=0;
	key[0]=0,parent[0]=0;
	while(count<V-1)
	{
		int u=minkey(key,mst);
		mst[u]=true;
		count++;
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mst[v]==false && graph[u][v]<key[v])
				parent[v]=u,key[v]=graph[u][v];
		}
	}
	printmst(parent,graph);
}
			
// driver program to test above function
int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}
