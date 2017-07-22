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
	int *lis=new int[n],i,j;
	for(i=0;i<n;i++)
		lis[i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && (1+lis[j])>lis[i])
				lis[i]=lis[j]+1;
		}
	}
	int max=lis[0];
	for(int i=0;i<n;i++)
	{
		if(lis[i]>max)
			max=lis[i];
	}
	cout<<max<<endl;
	return 0;
}	
