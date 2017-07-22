#include<iostream>
using namespace std;
//Recursive Solution
bool subset_sum_recursive(int arr[],int n,int sum)
{
	if(sum==0)
		return true;
	if(n==0)
		return false;
	if(arr[n-1] >sum)
		return subset_sum_recursive(arr,n-1,sum);
	return subset_sum_recursive(arr,n-1,sum-arr[n]) || subset_sum_recursive(arr,n-1,sum);
}
//DP Solution
bool subset_sum(int arr[],int n,int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int j=1;j<=sum;j++)
		dp[0][j]=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(arr[i-1] > j)
				dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
		}
	}
	return dp[n][sum];
}
		
