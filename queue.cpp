#include<iostream>
#include<queue>
#include<deque>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
struct elem{
	int x,y;
};
int R,C;
bool isValid(int x,int y)
{
	return (x>=0 && x<R && y>=0 && y<C);
}
bool isDelim(elem t)
{
	return t.x==-1 && t.y==-1;
}
bool checkall(int arr[][C])
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(arr[i][j]==1)
				return true;
		}
	}
	return false;
}
int rotten_oranges(int arr[][C])
{
	queue<elem> q;
	int ans=0;
	int i=0,j=0;
	elem temp;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(arr[i][j]==2)
			{
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
		}
	}
	temp.x=-1;
	temp.y=-1;
	q.push(temp);	//Delimeter...
	while(!q.empty())
	{
		bool flag=false;
		while(!isDelim(q.front()))
		{
			temp=q.front();
			q.pop();
			if(isValid(temp.x+1,temp.y)&& arr[temp.x+1][temp.y]==1)
			{
				if(!flag){
					ans++;
					flag=true;
				}
				temp.x++;
				q.push(temp);
				temp.x--;
			}
			if(isValid(temp.x-1,temp.y)&& arr[temp.x-1][temp.y]==1)
                        {
                                if(!flag){
                                        ans++;
					flag=true;
				}
                                temp.x--;
                                q.push(temp);
                                temp.x++;
                        }
			if(isValid(temp.x,temp.y+1)&& arr[temp.x][temp.y+1]==1)
                        {
                                if(!flag){
                                        ans++;
					flag=true;
				}
                                temp.y++;
                                q.push(temp);
                                temp.y--;
                        }
			if(isValid(temp.x,temp.y-1)&& arr[temp.x][temp.y-1]==1)
                        {
                                if(!flag){
                                        ans++;
					flag=true;
				}
                                temp.y--;
                                q.push(temp);
                                temp.y++;
                        }
		}
		i(!q.empty())
		{
			temp.x=-1;
			temp.y=-1;
			q.push(temp);
		}
	}
	return checkall(arr)?-1:ans;
}
bool compdec(int a,int b)
{
	return a>b;
}

void generate_bin(int n)
{
	queue<string> q;
	q.push("1");
	cout<<endl;
	while(n--)
	{
		string s1=q.front();
		q.pop();
		//printf("%*.*s",(int)10-s1.length(),(int)s1.length(),s1);
		cout<<s1<<endl;
		string s2=s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}
}

void populate_array(queue<int> q0,queue<int> q1,queue<int> q2,int *aux,int &size)
{
	int i=0;
	while(!q0.empty())
	{
		aux[i++]=q0.front();
		q0.pop();
	}
	while(!q1.empty())
	{
		aux[i++]=q1.front();
		q1.pop();
	}
	while(!q2.empty())
	{
		aux[i++]=q2.front();
		q2.pop();
	}
	size=i;
}

void find_max_subarray_k(int *arr,int n,int k)
{
	deque<int> dq;
	int i=0;
	//Dequeue the array 
	for(i=0;i<k;i++)
	{
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for(;i<n;i++)
	{
		cout<<arr[dq.front()]<<" ";
		while(!dq.empty() && dq.front()<=i-k)
			dq.pop_front();	
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<arr[dq.front()]<<" ";
}
bool max_multiple_of3(int *arr,int &size,int *aux)
{
	queue<int> q0,q1,q2;
	int i,sum=0;
	sort(arr,arr+size);
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
		if(arr[i]%3==0)
			q0.push(arr[i]);
		else if(arr[i]%3==1)
			q1.push(arr[i]);
		else if(arr[i]%3==2)
			q2.push(arr[i]);
	}
	cout<<"Sum:"<<sum<<endl;
	if((sum%3)==1)
	{
		if(!q1.empty())
			q1.pop();
		else
		{
			if(!q2.empty())
				q2.pop();
			if(!q2.empty())
				q2.pop();
			else
				return false;
		}
	}
	else if((sum%3)==2)
        {
                if(!q2.empty())
                        q2.pop();
                else
                {
                        if(!q1.empty())
                                q1.pop();
                        if(!q1.empty())
                                q1.pop();
                        else
                                return false;
                }
        }
	aux=new int[size];
	populate_array(q0,q1,q2,aux,size);
	sort(aux,aux+size,compdec);
	for(i=0;i<size;i++)
		cout<<aux[i];
	cout<<endl;
	return true;	
}		
int main()
{
	int *arr,size,*aux;
	cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	if(!max_multiple_of3(arr,size,aux))
		cout<<"Can't find an Integer array like this.."<<endl;
	int a1[]={1,2,3,1,4,5,2,3,6};
	find_max_subarray_k(a1,9,3);
	generate_bin(5);
	cout<<endl;	
	return 0;
}
