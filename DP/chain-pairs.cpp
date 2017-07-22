#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
/*struct pair{
	int first,second;
};*/
bool compare(pair<int,int> &p1,pair<int,int> &p2)
{
	return p1.first<p2.first;
}
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back(pair<int,int>(a,b));
	}
	sort(v.begin(),v.end(),compare);
	int *dp[v.size()+1];
	for(int i=0;i<v.size();i++)
		dp[i]=1;
	for(int i=1;i<v.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[j].second<v[i].first && 1+dp[j]<dp[i])
				dp[i]=dp[j]+1;
		}
	}
	int max=-9999;
	for(int i=0;i<v.size();i++)
	{
		if(max<dp[i])
			max=dp[i];
	}
	cout<<max<<endl;
	return 0;
}
		
	
		
