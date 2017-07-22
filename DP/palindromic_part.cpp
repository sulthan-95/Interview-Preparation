#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	//To find the palindormic partioning
	bool Pal[n][n];	//Stores whether a substring of i..j is palindrome or not..
	int Cost[n];
	for(int L=2;L<=n;L++)	//substring length
	{
		for(int i=0;i<n-L+1;i++)
		{
			int j=i+L-1;	//substring between i and j
			if(L==2)
				P[i][j]=(str[i]==str[j]);
			else
				P[i][j]=(str[i]==str[j]) && Pal[i+1][j-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(P[0][i])
			C[i]=0;
		else
		{
			C[i]=9999;
			for(int k=0;k<i;k++)
			{
				if(P[k+1][i] && C[k]+1<C[i])
					C[i]=C[k]+1;
			}
		}
	}
	cout<<C[n-1]<<endl;
}
