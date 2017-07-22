#include<iostream>
using namespace std;
int main()
{
	int a=1,b=0;
	b=a++ + ++a;
	cout<<a<<","<<b<<endl;
	return 0;
}
