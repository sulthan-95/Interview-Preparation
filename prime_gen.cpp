#include <iostream>
#include <string.h>
using namespace std;
//typedef long long int ll;
int main() {
	// your code here
	int t;
	long long int m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		bool arr[n+1];
		for(int i=0;i<=n;i++)
			arr[i]=false;
		//memset(arr,false,n+1);
		arr[0]=true;
		arr[1]=true;
		for(int i=2;i*i<=n;i++)
		{
			if(!arr[i])
			{
				for(int j=i*i;j<=n;j+=i)
					arr[j]=true;
			}
		}
		for(int i=m;i<=n;i++)
		{
			if(!arr[i])
				cout<<i<<endl;
		}
		cout<<endl;
	}
	return 0;
}
