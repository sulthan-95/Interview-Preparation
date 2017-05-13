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
        max=lt;
        else
        max=rt;
        if(val>max)
        max=val;
        max=rt;
        if(val>max)
        max=val;
    }
    return max;
}
int findmin(struct btree *root)
{
    int val,lt,rt,min=10000;
    if(root!=NULL)
    {
        val=root->data;
        lt=findmin(root->left);
        rt=findmin(root->right);
        if(lt<rt)
        min=lt;
        else
        min=rt;
        if(val<min)
        min=val;
    }
    return min;
}
int findmaxnonrec(struct btree *root)
{
    int max=-9999;
    struct btree *t;
    queue<struct btree *>q;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->data>max)
        max=t->data;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return max;
}
int findminnonrec(struct btree *root)
{
    int min=9999;
    struct btree *t;
    queue<struct btree *>q;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->data<min)
        min=t->data;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return min;
}
int find(struct btree *root,int val)
{
    int t;
    if(root==NULL)
    return 0;
    if(root->data==val)
    return 1;
    else
    {
        t=find(root->left,val);
        if(t!=0)
        	return t;
        else
        	return find(root->right,val);
    }
    return 0;
}
int findnonrec(struct btree *root,int val)
{
    struct btree *t;
    if(root==NULL)
    return 0;
    queue<struct btree *>q;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(val==t->data)
        return 1;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return 0;
}
int sizetree(struct btree *root)
{
    if(root==NULL)
    	return 0;
    else
    	return(sizetree(root->left)+1+sizetree(root->right));
}
int sizetreenonrec(struct btree *root)
{
    struct btree *t;
    int count=0;
    queue<struct btree *>q;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        count++;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return count;
}
void levelorderrev(struct btree *root)
{
    struct btree *t;
    stack<struct btree *>s;
    queue<struct btree *>q;
    if(root==NULL)
    	return;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->right)
        q.push(t->right);
        if(t->left)
        q.push(t->left);
        s.push(t);
    }
    while(!s.isempty())
    {
        cout<<"\n"<<s.pop()->data;
    }
}
void deletetree(struct btree *root)
{
    if(root==NULL)
    return;
    deletetree(root->left);
    deletetree(root->right);
    delete root;
}
void deletetreenonrec(btree *root)
{
	queue<btree *>q;
	btree *t;
	if(root==NULL)
		return;
	q.push(root);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
		delete t;
	}
}
int heighttree(struct btree *root)
{
    int lh,rh;
    if(root==NULL)
    return -1;
    lh=heighttree(root->left);
    rh=heighttree(root->right);
    if(lh>rh)
    return(lh+1);
    else
    return(rh+1);
}
int heighttreenonrec(struct btree *root)
{
    int h=-1;
    if(root==NULL)
    return -1;
    queue<struct btree *>q;
    q.push(root);
    q.push(NULL);
    struct btree *t;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==NULL)
        {
        	if(!q.empty())
        		q.push(NULL);
        	h++;
        }
        else
        {
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
    }
    return h;
}
int deepestnode(struct btree *root)
{
    struct btree *t;
    queue<struct btree *>q;
    if(root==NULL)
    return 0;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return t->data;
}
struct btree * deepnode(struct btree *root)
{
    struct btree *t;
    queue<struct btree *>q;
    if(root==NULL)
    return NULL;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return t;
}
struct btree * findnode(struct btree *root,int val)
{
    struct btree *t;
    if(root==NULL)
    return NULL;
    if(root->data==val)
    return root;
    else
    {
        t=findnode(root->left,val);
        if(t!=NULL)
        return t;
        else
        return findnode(root->right,val);
    }
    return NULL;
}
void deletenode(struct btree *root,int val)
{
    struct btree *f=findnode(root,val);
    struct btree *d=deepnode(root);
    f->data=d->data;
    deletetree(d);
}
int noofleaves(struct btree *root)
{
    struct btree *t;
    queue<struct btree *>q;
    if(root==NULL)
    return 0;
    int count=0;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->left==NULL && t->right==NULL)
        count++;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return count;
}
int nooffullnodes(struct btree *root)
{
    struct btree *t;
    queue<struct btree *>q;
    if(root==NULL)
    return 0;
    int count=0;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->left!=NULL && t->right!=NULL)
        count++;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return count;
}
int noofhalfnodes(struct btree *root)
{
    struct btree *t;
    queue<struct btree *>q;
    if(root==NULL)
    return 0;
    int count=0;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if((t->left==NULL && t->right!=NULL)||(t->left!=NULL && t->right==NULL))
        count++;
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return count;
}
int identical(struct btree *root1,struct btree *root2)
{
    if(!root1 && !root2)
    return 1;
    if(!root1 || !root2)
    return 0;
    return(root1->data==root2->data && identical(root1->left,root2->left)&&identical(root1->right,root2->right));
}
int diameter(struct btree *root)
{
    if(root==NULL)
    return 0;
    int lh=heighttree(root->left);
    int rh=heighttree(root->right);
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    return max(lh+rh+1,max(ld,rd));
}
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int maxsumlevel(struct btree *root)
{
    if(root==NULL)
    return 0;
    int cursum=0;
    int maxsum=0;
    int level=1;
    int maxlevel=0;
    queue<struct btree *>q;
    q.push(root);
    q.push(NULL);
    struct btree *t;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==NULL)
        {
            if(cursum >maxsum)
            {
                maxsum=cursum;
                maxlevel=level;
            }
            cursum=0;
            if(!q.empty())
            q.push(NULL);
            level++;
        }
        else
        {
            cursum=cursum+t->data;
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
    }
    return maxlevel;
}
void printarray(int v[],int l)
{
    int i;
    cout<<"\n";
    for(i=0;i<l;i++)
    cout<<"\t"<<v[i];
}
void printpath(struct btree *root,int path[],int pl)
{
    if(root==NULL)
    return;
    path[pl]=root->data;
    pl++;
    if(root->left==NULL && root->right==NULL)
    printarray(path,pl);
    else
    {
        printpath(root->left,path,pl);
        printpath(root->right,path,pl);
    }
}
int checksumpath(struct btree *root,int s)
{
    int rs;
    if(root==NULL)
    {
        if(s==0)
        return 1;
        else
        return 0;
    }
    else
    {
        rs=s-root->data;
        if((root->left && root->right)||(!root->left && !root->right))
        return(checksumpath(root->left,rs)|| checksumpath(root->right,rs));
        else if(root->left)
        return checksumpath(root->left,rs);
        else
        return checksumpath(root->right,rs);
    }
}
int sumtree(struct btree *root)
{
    if(root==NULL)
    return 0;
    else
    return (root->data+sumtree(root->left)+sumtree(root->right));
}
struct btree * mirror(struct btree *root)
{
    struct btree *t;
    if(root)
    {
        mirror(root->left);
        mirror(root->right);
        t=root->left;
        root->left=root->right;
        root->right=t;
    }
    return root;
}
int ismirrors(struct btree *root1,struct btree *root2)
{
    if(root1==NULL && root2==NULL)
    return 1;
    if(root1==NULL || root2==NULL)
    return 0;
    if(root1->data!=root2->data)
    return 0;
    else
    return ismirrors(root1->right,root2->left)&&ismirrors(root1->left,root2->right);
}
int ancestors(struct btree *root,int n)
{
    if(root==NULL)
    return 0;
    if((root->left->data==n) || (root->right->data==n) || ancestors(root->left,n)|| ancestors(root->right,n))
    {
    cout<<"\n"<<root->data;
    return  1;
    }
