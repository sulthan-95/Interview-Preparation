#include<iostream>
using namespace std;
void knapsack(int val[100],int wt[100],int n,int W)
{
	int knap[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				knap[i][j]=0;
			else if(wt[i-1]<=j)
			{
				knap[i][j]=max(val[i-1]+knap[i-1][j-wt[i-1]],knap[i-1][j]);
			}
			else
				knap[i][j]=knap[i-1][j];
		}
	}
	cout<<knap[n][W]<<endl;	
}
			
int main()
{
	int n,W,val[100],wt[100];
	cin>>n;
	cin>>W;
	for(int i=0;i<n;i++)
		cin>>val[i];
	for(int i=0;i<n;i++)
		cin>>wt[i];
	knapsack(val,wt,n,W);
	return 0;
}
