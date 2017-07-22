#include<iostream>
using namespace std;
int array[m][n+1];
int count( int S[], int m, int n )
{
    
    if (n == 0)
        return 1;
     
    
    if (n < 0)
        return 0;
 
    
    if (m <=0 && n >= 1)
        return 0;
	
    if(array[m][n]!=0)
	return array[m][n];		
   
    array[m][n]=count( S, m - 1, n ) + count( S, m, n-S[m-1] );

}

int main(int argc,char *argv[])
{
	int n,m;
	cin>>n;
	cout<<"\nEnter the no. of dimensions.";
	cin>>m;
	int *den=new int[m]
	for(int i=0;i<m;i++)
		cin>>den[i];
	for(int i=0;i<=n;i++);
	// A new DP array dp[i][j] with rows for 'i' money upto 'j'th denomination included or not
	int dp[n+1][m];
	for(int i=0;i<m;i++)
		dp[0][i]=1;
	for(int i=1;i<=n;i++)	//For each i amount
	{
		for(int j=0;j<m;j++)// For j th denomination 
		{
			int x=(i-den[j])?dp[i-den[j]][j]:0;	//Including jth denomination
			int y=(j>=1)?dp[i][j-1]:0;		//Not including jth denomination
	  		dp[i][j]=x+y;
		}
	}
	cout<<dp[n][m-1]<<endl;
	return 0;
}
		
