#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int *arr,int low,int high)
{
	int pivot=arr[high],i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}
void q_sort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		q_sort(arr,low,pi-1);
		q_sort(arr,pi+1,high);
	}
}
int main()
{
	int *arr,n;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	q_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
	return 0;
}
