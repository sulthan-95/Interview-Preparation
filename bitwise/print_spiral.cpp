#include<iostream>
using namespace std;
int main()
{
	int A[5][5],rows=0,columns=0,rowe=4,columne=4;
	//Here you get the 5*5 matrix
	while(rows<=rowe && columns<=columne)
	{
		int i=rows,j=columns;
		for(j=columns;j<=columne;j++){cout<<A[i][j]<<" ";}
		for(i=rows+1,j--;i<=rowe;i++)	cout<<A[i][j]<<" ";
		for(j=columne-1,i--,j>=columns;j--)	cout<<A[i][j]<<" ";
		for(i=rowe-1,j++,i>=rows;i--)	cout<<A[i][j]<<" ";
		rows++;rowe--;columns++;columne--;
	}
	return 0;
}
