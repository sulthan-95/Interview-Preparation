#include<iostream>
using namespace	std;
bool bin_search(int *a,int l,int h,int key)
{
	if(l>h) 
		return false;
	int mid=(l+h)/2;
	if(a[mid]==key)
		return true;
	if(a[l]<=a[mid])
	{
		if(key>=a[l] && key<a[mid])
			return bin_search(a,l,mid-1,key);
		return bin_search(a,mid+1.h,key);
	}
	if(key<=a[h] && key>a[mid])
		return bin_search(a,mid+1,h,key);
	return bin_search(a,l,mid-1,key);
}
int main()
{
	int n,key;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>key;
	if(bin_search(a,0,n-1,key))
		cout<<"Key Found"<<endl;
	return 0;
}
	
	
