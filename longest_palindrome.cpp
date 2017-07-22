#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string s;
	map<char,int> mp;
	bool flag=false;
	int len=0,max=0,st=0,ft=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(mp.find(s[i])==mp.end())
		{
			if(flag)
			{
				mp.clear();
				len=0;
				flag=false;
			}
			else
				mp.insert(pair<char,int>(s[i],i+1));
		}
		else
		{
			int start=mp[s[i]];
			int end=i+1;
			if(end-start<=2)
				flag=true;
			if(flag)
			{
				len=end-start+1;
				if(len>max)
				{
					st=start-1;
					ft=end-1;
					max=len;
				}
			}
			else
				mp[s[i]]=i+1;
		}
	}
	string s2=s.substr(st,ft-st+1);
	cout<<st<<"\n"<<len<<endl;
	cout<<s2<<endl;
	return 0;
}
