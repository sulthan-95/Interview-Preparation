#include<iostream>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	int table[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	for(;n;n>>=4)
	{
		count+=table[n & 0xF];
	}
	if(count==1)
		cout<<"Yes\n";
	cout<<count<<endl;
	return 0;
}
