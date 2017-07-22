#include<iostream>
using namespace std;
int count_ways(int n)
{
	if(n==0 || n==1)
		return 1;
	return count_ways(n-1)+count_ways(n-2);
}
int iterative_count(int n)
{
	int res[n];
	res[0]=res[1]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=2&& j<=i;j++)
		{
			res[i]+=res[i-j];
		}
	}
	return res[n-1];
}
int main()
{
	int n;
	cin>>n;
	cout<<count_ways(n)<<endl;
	return 0;
}
