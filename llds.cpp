#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cassert>
using namespace std;
struct linkedlist{
	int x,y;
	linkedlist *next;
	linkedlist(int x,int y)
	{
		this->x=x;
		this->y=y;
		this->next=NULL;
	}
}typedef node;
void insert(node *head,int x,int y)
{
	node *n=new node(x,y);
	if(!head){
		head=n;
		return;
	}
	while(head->next!=NULL)
		head=head->next;
	head->next=n;
}
void delete_middle(node *head)
{
	if(!head || !(head->next) || !(head->next->next))
		return;
	node *prev=NULL,*t=head->next;
	int sample_y=head->y;
	while(t)
	{	
		if(t->y != sample_y)
			break;			
		prev=t;
		t=t->next;
	}
	head->next=prev;
	if(t)
	{
		while(t->next)
			t=t->next;
		prev->next->next=t;		
	}
	
}


//Set 1:BT to DLL
void BTtoDLL(Node *root,Node **head)
{
	if(root==NULL)
		return;
	node *pre=NULL;
	BTtoDLL(root->left,head);
	if(pre==NULL)
		*head=root;
	else
	{
		root->left=pre;
		pre->right=root;
	}
	pre=root;
	BTtoDLL(root->right,head);
}

//Set 2:
void BTtreetoDLL(node *root,node **head)
{
	if(root==NULL)
		return;
	BTtreetoDLL(root->right,head);
	root->right=*head;
	if((*head)!=NULL)
		(*head)->left=root;
	*head=root;
	BTtreetoDLL(root->right,head);
}
