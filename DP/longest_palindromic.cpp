#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int len=1,n=A.length(),start=0,i,j,k;
    int dp[n];
    //memset(dp,false,sizeof(dp));
    for(i=0;i<A.length();i++)
        dp[i]=1;
    for(i=0;i<A.length()-1;i++)
    {
        if(A[i]==A[i+1])
            dp[i]=2;
    }
    for(k=3;k<=n;k++)
    {
        for(i=0;i<n-k+1;i++)
        {
            j=i+k-1;
            if(A[i]==A[j])
            {   
		if(dp[i+1]==(j-i-1))
			dp[i]=k;
	    	else if(dp[i+1]>(j-i-1) && A[i+1]==A[j-1])
			dp[i]=k;
	   }
        }
    }
    for(i=0;i<n;i++)
    	cout<<dp[i]<<" ";
    for(i=0;i<n;i++)
    {
        if(dp[i]>len)
        {
            start=i;
            len=dp[i];
        }
    }
    string s=A.substr(start,len);
    return s;
    
}
int main() {
	// your code goes here
	string s("abbcccbbbcaaccbababcbcabca");
	cout<<longestPalindrome(s)<<endl;
	return 0;
}
