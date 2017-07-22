#include<iostream>
#include<math.h>
using namespace std;
int find_pow(int x,int n,int d)
{
	if(n==0)
		return 1;
	if(n==1)
	{
		int q=x/d,rem=0;
        	if(x<0)
        	{
                	q=-q;
                	rem=(q+1)*d+x;
        	}
        	else
                	rem=x-(q*d);
		return (rem*rem)%d;
	}
	return find_pow(x,n/2,d);
}
	
int powmod(int x, int n, int d) {
    if(n==0)
        return 1;
    if(x==0)
	return 0;
    if(n<0)
    {    
	x=1/x;
	n=-n;
    }
    if(n&1)
    {
        int q=x/d,rem=0;
        if(x<0)
        {
		q=-q;
		rem=(q+1)*d+x;
	}
	else
		rem=x-(q*d);
	return (rem*find_pow(x,n-1,d))%d;
    }
    else
    	return find_pow(x,n,d)%d;
}
	
int main()
{
	cout<<powmod(2,3,3)<<endl;
	return 0;
}
