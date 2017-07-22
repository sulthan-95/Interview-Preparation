#include<iostream>
#include<stdio.h>
using namespace std;
int minJumps(int arr[],int n)
{
	int steps=0,maxreach=0,jumps=1;
	if(arr[0]==0)
		return -1;
	steps=maxreach=arr[0];
	for(int i=1;i<n;i++)
	{
		if(i==n-1)
			return jump;
		maxreach=max(maxreach,i+arr[i]);
		steps--;
		if(steps==0)
		{
			jumps++;
			if(i>=maxreach)
				return -1;
			steps=maxreach-i;
		}
	}
}
int main()
{
	int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    	int size = sizeof(arr)/sizeof(int);
 
    	// Calling the minJumps function
    	printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    	return 0;
}
