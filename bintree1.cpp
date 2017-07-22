#include<iostream>
#include<queue>
#include"stack.h"
using namespace std;
struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};
struct btree *root=NULL;
struct btree *root1=NULL;
struct btree* insert(struct btree *root,int d)
{
    struct btree *n;
    struct btree *t;
    n=new struct btree;
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    if(!root)
    {
        root=n;
        return root;
    }
    queue<struct btree *>Q;
    Q.push(root);
    while(!Q.empty())
    {
        t=Q.front();
        Q.pop();
        if(t->left)
        Q.push(t->left);
        else
        {
            t->left=n;
            return root;
        }
        if(t->right)
        Q.push(t->right);
        else
        {
            t->right=n;
            return root;
        }
    }
}
void preorder(struct btree *root)
{
    if(root)
    {
        cout<<"\n"<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct btree *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<"\n"<<root->data;
        inorder(root->right);
    }
}
void postorder(struct btree *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<"\n"<<root->data;
    }
}
void preordernonrec(struct btree *root)
{
    stack<struct btree *>S;
    while(1)
    {
        while(root)
        {
            cout<<"\n"<<root->data;
            S.push(root);
            root=root->left;
        }
        if(S.isempty())
        break;
        root=S.pop();
        root=root->right;
    }
    S.deletestack();
}
/*******************************************/
//Post order non recursive nature not verified//
void postnonrec(btree *root)
{
	stack<btree *> S;
	btree *prev=NULL;
	do{
		while(root)
		{
			S.push(root);
			root=root->left;
		}
		while(root==NULL && !S.empty())
		{
			root=S.top();
			if(root->right==NULL || root->right==prev)
			{
				cout<<root->data<<endl;
				S.pop();
				previous=root;
				root=NULL;
			}
			else
				root=root->right;
		}
				
	}while(!S.empty());
	S.deletestack();
}
/*************************************/
void inordernonrec(struct btree *root)
{
    stack<struct btree *>S;
    while(1)
    {
        while(root)
        {
            S.push(root);
            root=root->left;
        }
        if(S.isempty())
        break;
        root=S.pop();
        cout<<"\n"<<root->data;
        root=root->right;
    }
    S.deletestack();
}
void postordernorec(struct btree *root)
{
	stack<btree *>S,<btree *>S1;
	S.push(root);
	while(S.isempty())
	{
		root=S.pop();
		S1.push(root);
		if(root->left)
			S.push(root->left);
		if(root->right)
			S.push(root->right);
	}
	while(S1.isempty())
	{
		root=S1.pop();
		cout<<"\n"<<root->data;
	}
}
void levelorder(struct btree *root)
{
    queue<struct btree *>q1;
    struct btree *t;
    if(root==NULL)
    return;
    q1.push(root);
    while(!q1.empty())
    {
        t=q1.front();
        q1.pop();
        cout<<"\n"<<t->data;
        if(t->left)
        q1.push(t->left);
        if(t->right)
        q1.push(t->right);
    }
}
int findmax(struct btree *root)
{
    int val,lt,rt,max=-9999;
    if(root)
    {
        val=root->data;
        lt=findmax(root->left);
        rt=findmax(root->right);
        if(lt>rt)
		return lt+1;
	else
		return rt+1;
    }
}

