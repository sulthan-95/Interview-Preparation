#include<iostream>
using namespace std;
int Matrix_Chain_Order(int P[],int len)
{
	int M[n-1]M[n-1];
	//Cost of multiplying the matrix with its own
	for(i=1;i<n;i++)
		M[i][i]=0;
	for(int l=2;l<n;l++)
	{
		for(int i=1;i<n-l+1;i++)
		{
			int j=i+l-1;
			M[i][j]=9999;
			//Min cost of Matrix chain of i..j
			for(int k=i;k<j;k++)
			{
				int thiscost=M[i][k] + M[k+1][j]+ P[i-1]*P[k]*P[j];
				if(thiscost>M[i][j])
					M[i][j]=thiscost;
			}
		}
	}
	return M[0][n-2];
}	
