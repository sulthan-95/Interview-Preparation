#include<iostream>
#include<string>
using namespace std;
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	string s1,s2;
	cout<<"\nEnter the strings..";
	cin>>s1>>s2;
	int m=s1.length(),n=s2.length();
	int dp[m+1][n+1];
	//Here dp array is for cost of changing the s1 to s2;
	//dp[i][j] signifies the cost of changing s1 upto i to s2 upto j; 
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)		//s1 is empty,.. so j insertions for each j in s2
				dp[i][j]=j;
			else if(j==0)		//s2 is empty.. so to remove i elements from s1 for each i
				dp[i][j]=i;
			else if(s1[i-1]==s2[j-1]) // if character is same then the cost is same as previous one..
				dp[i][j]=dp[i-1][j-1];
			else
				//Insertion and Removal has cost of 1
				// Replacement has cost of 2
				//dp[i-1][j] => Insertion cost when added with 1
				//dp[i][j-1] => Removal cost when added with 1
				//dp[i-1][j-1] => Replacement cost when added with 2
				// So minimum among 3
				dp[i][j]=min(1+min(dp[i-1][j],dp[i][j-1]),2+dp[i-1][j-1]);
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}

			
				
		
