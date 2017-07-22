//The following program deals with problem when there are k floors and n eggs and have
// to find the minimum no. of trials needed to find the critical floor from which egg can be dropped
#include<iostream>
using namespace std;
int eggfloor(int n,int k)
{
	int result[n+1][k+1];
	for(int i=1;i<=n;i++)
	{
		result[i][1]=1; //Only one floor
		result[i][0]=0; //No floor
	}
	for(int j=1;j<=k;j++)
		result[1][j]=j;	//One egg..so j attempts for every floor
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			result[i][j]=100000;
			for(x=2;x<=j;x++) // For each floor find out maximum of egg breaking and non breaking..
			{
				int res=1+max(result[i-1][x-1],result[i-1][j-x]); //Find the maximum of x floors among j floors..
				if(res<result[i][j])
					result[i][j]=res;
			}
		}
	}
	return result[n][k];
}
		
int main()
{
	int n=2,k=4;
	cout<<eggfloor(n,k)<<endl;
	return 0;
}
