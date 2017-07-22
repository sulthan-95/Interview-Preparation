#include<iostream>
#define MAX -9999
using namespace std;
//Very High in Time Complexity..Need optimization..
int recursive(int price[],int n)
{
	if(n<=0)
		return 0;
	int value=-9999;
	for(int i=0;i<n;i++)
		value=max(value,price[i]+recursive(price,n-i-1));
	return value;
}
int cutrod(int price[],int n)
{
	int i,j;
	int cutprice[n+1]={0};
	for(i=1;i<=n;i++)
	{
		int value=MAX;
		for(j=0;j<i;j++)
			value=max(value,price[i]+cutprice[i-j-1];
		cutprice[i]=value;
	}
	return cutprice[n];
}
