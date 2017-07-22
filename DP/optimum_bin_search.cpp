#include<iostream>
using namespace std;
int optimum_cost_recursive(int *freq,int i,int j)
{
	if(j>i)
		return 0;
	if(j==i)
		return freq[i];
	int sum=0;
	for(int t=i;t<=j;t++)	//Finds the cost of all nodes when this node is made as the root of a subtree
		sum+=freq[t];
	int min=INT_MAX;
	//Make every node as root
	for(int r=i;r<=j;r++)
	{
		int cost=optimum_cost_recursive(freq,i,r-1)+optimum_cost_recursive(freq,i+1,r);
		if(cost<min)
			min=cost;
	}
	return min+sum;
}
int sum(int *freq,int i,int j)
{
	if(i==j)
		return freq[i];
	return freq[i]+sum(freq,i+1,j);
}
		
//DP using auxillary matrix build up in bottom up manner
int optimum_cost(int *freq,int s,int n)
{
	int dp[n+1][n+1];
	for(int i=0;i<n;i++)
		dp[i][i]=freq[i];
	//For all the subtrees of size greater than 1
	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++)
		{
			int j=i+L-1;
			dp[i][j]=INT_MAX;
			for(int r=i;r<=j;r++)
			{
				int c=(r>i)?dp[i][r-1]:0+(r<j)?dp[r+1][j]:0+sum(freq,i,j);
				if(c<dp[i][j])
					dp[i][j]=c;
			}
		}
	}
	return dp[0][n-1];
}
int main()
{
	int n;
	cin>>n;
	int *freq=new int[n+1],*node=new int[n+1];
	for(int i=0;i<n;i++)
		cin>>node[i];
	for(int i=0;i<n;i++)
		cin>>freq[i];
	cout<<optimum_cost(freq,0,n)<<endl;
	return 0;
}
