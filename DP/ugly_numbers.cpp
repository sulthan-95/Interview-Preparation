#include<iostream>
#include<algorithm>
using namespace std;
/*long long int min(long long int a,long long int b,long long int c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	if(c<=a && c<=b)
		return c;
}*/
int main()
{
	int n,i2=0,i3=0,i5=0;
	cin>>n;
	long long int ugly[n+10];
	ugly[0]=1;
	long long int nm_2=2,nm_3=3,nm_5=5,nx_ugl=1;
	for(int i=1;i<n;i++)
	{
		nx_ugl=min(nm_2,min(nm_3,nm_5));
		ugly[i]=nx_ugl;
		if(nx_ugl==nm_2)	//Continous if's are used instead of else if such that ugly numbers with common factors of 2,3,5 
					//are not repeated
		{
			i2=i2+1;
			nm_2=ugly[i2]*2;
		}
		if(nx_ugl==nm_3)
		{
			i3=i3+1;
			nm_3=ugly[i3]*3;
		}
		if(nx_ugl==nm_5)
		{
			i5=i5+1;
			nm_5=ugly[i5]*5;
		}
	}
	cout<<nx_ugl<<endl;
	return 0;
}
