#include<iostream>
#include<stack>
#include<stdio.h>
#define max 100
using namespace std;
void insert_at_bottom(stack<int> &s,int item)
{
	if(s.empty())
		s.push(item);
	else
	{
		int temp=s.top();
		s.pop();
		insert_at_bottom(s,item);
		s.push(temp);
	}
}
void reverse(stack<int> &s)
{
	if(!s.empty())
	{
		int temp=s.top();
		s.pop();
		reverse(s);
		insert_at_bottom(s,temp);
	}
}
void _insert_(stack<int> &s,int item)
{
	if(s.empty() || item>s.top())
		s.push(item);
	else
	{
		int temp=s.top();
		s.pop();
		_insert_(s,item);
		s.push(temp);
	}
}
void sort(stack<int> &s)
{
	if(!s.empty())
	{
		int temp=s.top();
		s.pop();
		sort(s);
		_insert_(s,temp);
	}
}
void next_greater_element(int *arr,int n)
{
	stack<int> s;
	s.push(arr[0]);
	int elem=0,next;
	for(int i=1;i<n;i++)
	{
		if(!s.empty()){
			elem=s.top();
			s.pop();
		next=arr[i];
		while(elem<next)
		{
			cout<<elem<<"->"<<next<<endl;
			if(s.empty())
				break;
			elem=s.top();
			s.pop();
		}
		if(elem>next)
			s.push(elem);
		}
		s.push(next);
	}
	while(!s.empty())
	{
		cout<<s.top()<<"->"<<"-1";
		s.pop();
	}
}	
int main()
{
	stack<int> s;
	char exp[max];
	cout<<"Enter the postfix expression..";
	cin>>exp;
	int r,a,b;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]>=48 && exp[i]<=57)
		{
			r=s.top()-48;
			s.push(r);
		}
		else
		{
			if(!s.empty())
			{
				b=s.top();
				s.pop();
			}
			if(!s.empty())	
			{
				a=s.top();
				s.pop();
			}
			else{
				cout<<"Inavlid Expession..";
				break;
			}
			if(exp[i]=='+')
				a=a+b;
			else if(exp[i]=='-')
				a=a-b;
			else if(exp[i]=='*')
				a=a*b;
			else if(exp[i]=='/')
				a=a/b;
			else if(exp[i]=='^')
				a=a^b;
		}
		s.push(a);
	}
	if(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	else
		cout<<"\nInvalid Expression..";
	return 0;
}
