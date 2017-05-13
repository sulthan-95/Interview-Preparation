#include<iostream>
#include<stack>
#include<queue>
#include<stdio.h>
#define max 100
using namespace std;
struct btree{
	int data;
	btree *left;
	btree *right;
}typedef node;
node * newNode(int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
btree * deepest_node(btree *root)
{
	if(!root)
		return root;
	queue<btree *> q;
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	return root;
}
void node_deletion(btree *root,int data)
{
	if(!root)
		return;
	bool flag=false;
	btree *deep=deepest_node(root);
	queue<btree *>q;
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		if(root->data==data)
		{
			root->data=deep->data;
			flag=true;
		}
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	if(!flag)
		return;
	deep=NULL;
	delete root;
}
void print(int a[max],int n)
{
        for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
        cout<<endl;
}

void print_path(btree *root,int *path,int len)
{
	if(!root)
		return;
	path[len++]=root->data;
	if(root->left==NULL && root->right==NULL)
		print(path,len);	//Function that prints an array of len
	else
	{
		print_path(root->left,path,len);
		print_path(root->right,path,len);
	}
}
bool has_path_sum(btree *root,int sum)
{
	if(root==NULL)
		return sum==0;
	int remain=sum-root->data;
	return remain==0 || has_path_sum(root->left,remain) || has_path_sum(root->right,remain);
}

bool HasPathSum(btree *root,int sum)
{
	if(root==NULL)
		return sum==0;
	else
	{
		int remain=sum-root->data;
		if((root->left && root->right)||(!root->left && !root->right))
		{
			return HasPathSum(root->left,remain)||HasPathSum(root->right,remain);
		}
		else if(root->left)
			return HasPathSum(root->left,remain);
		else
			return HasPathSum(root->right,remain);
	}
}


bool AreMirror(btree *root1,btree *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return root1->data==root2->data && AreMirror(root1->left,root2->right) && AreMirror(root1->right,root2->left);
}	
	
/*void insert(node *root,int d)
{
	node *n=new node,*t;
	n->data=d;
	n->left=NULL;
	n->right=NULL;
	if(!root)
	{	root=n;
		return root;
	}
	queue<node *>q;
	q.push(root);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t->left)
			q.push(t->left);
		else
		{
			t->left=n;
			return root;
		}
		if(t->right)
			q.push(t->right);
		else
		{
			t->right=n;
			return root;
		}
	}
}
bool sumcheck(node *root)
{
	int l=0,r=0;
	if((root==NULL)||((root->left==NULL)&&(root->right==NULL)))
		return true;
	else
	{	if(root->left)
			l=root->left->data;
		if(root->right)
			r=root->right->data;
		if(root->data==(l+r)&&(sumcheck(root->left))&&sumcheck(root->right))
			return true;
		else
			return false;
	}
}
bool areid(node *root1,node *root2)
{
	if((!root1)&&(!root2))
		return true;
	if((!root1)||(!root2))
		return false;
	return (root1->data==root2->data&&areid(root1->left,root2->left)&&areid(root1->right,root2->right));
}
bool issubtree(node *t,node *s)
{
	if(s==NULL)
		return true;
	if(t==NULL)
		return false;
	if(areid(t,s))
		return true;
	return issubtree(t->left,s)||issubtree(t->right,s);
}*/
//int n=0,n1=0;
void makepreorder(node *root,int *a,int &n)
{
	if(root==NULL)
		return;
	a[n++]=root->data;
	makepreorder(root->left,a,n);
	makepreorder(root->right,a,n);
}
void preordernonrec(node *root,int *a,int &n)
{
    stack<node *>S;
    while(1)
    {
        while(root)
        {
            a[n++]=root->data;
            S.push(root);
            root=root->left;
        }
        if(S.empty())
        break;
        root=S.top();
		S.pop();
        root=root->right;
    }
    //S.deletestack();
}
bool isSubtree(node *t,node *s)
{
	int *a=new int[max],*b=new int[max],flag=0,n=0,n1=0;
	makepreorder(t,a,n);
	makepreorder(s,b,n1);
	cout<<"n:"<<n<<"\nn1:"<<n1<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n1;i++)
		cout<<b[i]<<" ";
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[0])//&&(n1+(i+1)-n>=0))
		{
			flag=1;
			for(int j=1,k=i+1;j<n1;j++,k++)
			{
				if(a[k]==b[j])
					flag=1;
				else 
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
			return true;
	}
	return false;
}
int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("\nTree S is subtree of tree T\n");
    else
        printf("\nTree S is not a subtree of tree T\n");
    if(has_path_sum(T,70))
	cout<<"\nIt has a path sum of 70\n";
    if(has_path_sum(T,36))
      	cout<<"\nIt has a path sum of 36\n";
    return 0;
}
