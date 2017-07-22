#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//LIS
	int *lis=new int[n],*lds=new int[n],i,j;
	for(int i=0;i<n;i++)
	{
		lis[i]=1;
		lds[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && (1+lis[j])>lis[i])
				lis[i]=lis[j]+1;
		}
	}
	//LDS
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]<arr[j] && (1+lds[j] < lds[i]))
				lds[i]=lds[j]+1;
		}
	}
	//LBS
	int max=-9999;
	for(int i=0;i<n;i++)
	{
		if((lis[i]+lds[i]-1)>max)
			max=lis[i]+lds[i]-1;
	}
	cout<<max<<endl;
	return 0;
}	
