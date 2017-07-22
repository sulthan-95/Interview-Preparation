#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin>>s;
	int iscame[26];
	for(int i=0;i<26;i++)
		iscame[i]=0;
	int max=-999,length=0;
	int substr=1;
	for(int i=0;i<s.length();i++)
	{
		if(iscame[s[i]-48]!=substr)
		{
			iscame[s[i]-48]=substr;
			length++;
		}
		else    //When a character repeats
		{
			substr++;
			iscame[s[i]-48]=substr;
			if(length>max)
				max=length;
			length=1;
		}
	}
	cout<<max<<endl;
	return 0;
}
