#include<iostream>
using namespace std;
int factorial(int n)
{
	return (n==1||n==0)?1:factorial(n-1)*n;
}
int main(int args,char *argv[])
{
	int n;
	cout<<"\nEnter a number...";
	cin>>n;
	long int d=factorial(2*n)/(factorial(n+1)*factorial(n));
	cout<<"\nThe no. of unlabelled bin trees for it is..."<<d<<endl;
	return 0;
}
	
