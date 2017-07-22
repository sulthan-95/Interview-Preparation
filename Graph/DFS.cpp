#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#define MAX 10
using namespace std;
enum Color{WHITE,GRAY,BLACK};
void DFS(bool *visited,vector<vector<int> >v,int s)
{
	visited[s]=true;
	cout<<s<<"->";
	for(int i=0;i<v[s].size();i++)
	{
		if(visited[v[s][i]]==false)
		{
			visited[v[s][i]]=true;
			DFS(visited,v,V,v[s][i]);
		}
	}
}
//Cycle or not using recursion stack
bool is_cyclic_util(bool *visited,bool *recStack,vector<vector<int> >&v,int &V,int i)
{
	if(!visited[i])
	{
		visited[i]=true;
		recStack[i]=true;
		for(int j=0;j<v[i].size();j++)
		{
			if(!visited[v[i][j]] && is_cyclic_util(visited,recStack,v,V,v[i][j]))
			return false;
			else if(recStack[v[i][j]])
				return true;
		}
	}
	recStack[i]=false;
	return false;
}
bool is_cyclic(bool *visited,vector<vector<int> >&v,int &V)
{
	bool *visited=new bool[V],*recStack=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
		recStack[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(is_cyclic_util(visited,recStack,v,V,i);
			return true;
	}
	return false;
}
//Cycle or not using colors
bool check_cycl(int *color,vector<vector<int> >&v,int &V,int &i)
{
	color[i]=GRAY;
	for(int j=0;j<v[i].size();j++)
	{
		if(color[v[i][j]]==GRAY)
			return true;
		if(color[v[i][j]]==WHITE && check_cycl(color,v,V,v[i][j])
			return true;
	}
	color[i]=BLACK;
	return false;
}
bool cyclic_color(vector<vector<int> > &v,int &V)
{
	int *color=new int[V];
	fill_n(color,V,WHITE);
	for(int i=0;i<V;i++)
	{
		if(color[i]==WHITE)
		{
			if(check_cycl(color,v,V,i))
				return true;
		}
	}
	return false;
}
void topo_util(vector<vector<int> >&v,bool *visited,stack<int> &s,int &i)
{
	visited[i]=true;
	for(int j=0;j<v[i].size();j++)
	{
		if(visited[v[i][j]]==false)
			topo_util(v,visited,s,v[i][j]);
	}
	s.push(i);
}
void toplogical_sort(vector<vector<int> >&v,int V)
{
	bool *visited=new bool[V];
	fill_n(visited,V,false);
	stack<int> s;
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
			topo_util(v,visited,s,i);
	}	
	while(!s.empty())
	{
		cout<<s.top()<<"->";
		s.pop();
	}
}
void all_topo_util(vector<vector<int> >&v,int &V,vector<int>&indegree,vector<int>&res)
{
	bool flag=false;
	for(int i=0;i<V;i++)
	{
		if(!visited[i] && indegree[i]==0)
		{
			for(int j=0;j<v[i].size();j++)
				indegree[v[i][j]]--;
			res.push_back(i);
			visited[i]=true;
			all_topo_util(v,V,indegree,res);
			
			//This part is for generating result vector
			visited[i]=false;
			res.erase(res.end()-1);
			for(int j=0;j<v[i].size();j++)
				indegree[v[i][j]]++;
			flag=true;
		}
	}
	if(!flag)
	{
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}
}
				
void all_topo_sort(vector<vector<int> >&v,int &V,vector<int> &indegree)
{
	bool *visited=new bool[V];
	vector<int> res;
	fill_n(visited,V,false);
	all_topo_util(v,V,visited,indegree,res);
}
int main()
{
	int E,s,d,V;
	cin>>V;
	vector<vector<int> >v(V);
	vector<int> indegree;
	fill_n(indegree.begin(),indegree.end(),0);
	cout<<"\nEnter the no. of Edges..";
	cin>>E;
	cout<<"\nEnter the edge verices line by line..";
	for(int i=0;i<E;i++)
	{
		cin>>s>>d;
		v[s].push_back(d);
		//v[d].push_back(s);
		indegree[d]+=1;
	}
	//BFS
	bool visited[V];
	memset(visited,false,V);
	cout<<"Enter the start vertex..";
	cin>>s;
	DFS(visited,v,V,s);
	cout<<endl;
	return 0;
}
