#include<iostream>
using namespace std;
int main()
{
	unsigned int n=8,rev=n;
	int count=sizeof(n)*8;
	for(;n;n>>=1)
	{
		rev<<=1;
		rev|=n&1;
		count--;
	}
	rev<<=count;
	cout<<rev<<endl;
	return 0;
}
