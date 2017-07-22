#include<iostream>
using namespace std;
void reverse(char *begin,char *end)
{
	char temp=begin;
	while(begin<end)
	{
		temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}
}
void reverse_word(char *s)
{
	char *begin=NULL;
	char *temp=s;
	while(*temp)
	{
		if(begin==NULL && (*temp)!=' ')
			begin=temp;
		if(begin && ((*temp+1)==' ') || (*temp+1)=='\0')
		{
			reverse(begin,temp);
			begin=NULL;
		}
		temp++;
	}
}
			
int main()
{
	char *s="I love Programming";
	reverse_word(s);
	return 0;
}
