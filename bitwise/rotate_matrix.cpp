#include<iostream>
using namespace std;
int main()
{
	int matrix[5][5],n=5;
	//Get your matrix here..
	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-i-1;j++)
		{
			int t=matrix[i][j];
			matrix[i][j]=matrix[j][n-i-1];
			matrix[j][n-i-1]=matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1]=matrix[n-j-1][i];
			matrix[n-j-1][i]=t;
		}
	}
	return 0;
}
