#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
void newNode(node **root,int data)
{
	if(*root==NULL)
	{
		node *n=new node;
        	n->data=data;
        	n->left=NULL;
	        n->right=NULL;
		*root=n;
		return;
	}
	else if(data<(*root)->data)
		newNode(&((*root)->left),data);
	else
		newNode(&((*root)->right),data);
}
int main(int args,char *argv[])
{
	node *root,*current;
	newNode(&root,5);
	newNode(&root,3);
	newNode(&root,6);
	newNode(&root,2);
	newNode(&root,4);
	newNode(&root,7);
	newNode(&root,8);
	newNode(&root,1);
	stack<node *> s;
	current=root;
	s.push(current);
	current=current->left;
	while(1)
	{
		if(current)
		{
			s.push(current);
			current=current->left;
		}
		else
		{
			if(!s.empty()){
				current=s.top();
				s.pop();
				cout<<current->data<<"\n";
				current=current->right;
			}
			else
				break;
		}				
	}
	return 0;
}
			
