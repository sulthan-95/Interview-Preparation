#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	int count[n+1];
	//Count stores the no, of decodings possible for each length..
	count[0]=1;
	count[1]=1;
	for(int i=2;i<=n;i++)
	{
		count[i]=0;
		// If this character is greater than 0 then it should be making a seperate decoding sequence of its own
		if(s[i-1]>'0')
			count[i]=count[i-1];
		// If its inside 26 then this character along with previous character can make a
		// seperate decoding sequence.. Then after making these 2 as one or in other words
		// removing these 2 characters what is the maximum count.. that should be obtained...
		if(s[i-2]<'2' || s[i-2]=='2' && s[i-1]<'7')
			count[i]+=count[i-2];
	}	
	cout<<count[n]<<endl;
	return 0;
}
