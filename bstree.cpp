#include<iostream>
using namespace std;
struct node{
	int data;
	node *left,*right;
	int lcount,rcount;
	node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
		this->lcount=0;
		this->rcount=0;
	}
};
node * insert(node *root_t,int data)
{
	node *temp=new node(data);
	node *parent=root_t,*root=root_t;
	while(root)
	{
		parent=root;
		if(data<root->data)
		{
			root->lcount++;
			root=root->left;
		}
		else
		{
			root->rcount++;
			root=root->right;
		}
	}
	if(!root)
		root=temp;
	else if(data<parent->data)
		parent->left=temp;
	else
		parent->right=temp;
	return  root_t;
}
// Predecessor and successor of a node with data..
void pred_suc(node *root,node * &pre,node * &suc,int data)
{
	if(!root)
		return;
	if(root->data==data)
	{
		if(root->left!=NULL)
		{
			node *tmp=root->left;
			while(tmp->right)
				tmp=tmp->right;
			pre=tmp;
		}
		if(root->right!=NULL)
		{
			node *tmp=root->right;
			while(tmp->left)
				tmp=tmp->left;
			suc=tmp;
		}
	}
	if(data < root->data)
	{
		suc=root;
		pred_suc(root->left,pre,suc,data);
	}
	else
	{
		pre=root;
		pred_suc(root->right,pre,suc,data);
	}
}

void convert_BST_DLL(node *root,node * &head,node * &tail)
{
	if(root==NULL)
		return;
	
	if(root->left)
		convert_BST_DLL(root->left,head,tail);
	root->left=tail;
	if(tail)
		tail->right=root;
	else
		head=root;
	
	tail=root;
	if(root->right)
		convert_BST_DLL(root->right,head,tail);
}
//Construct BST from a preorder array
node *construct_bst_util(int *pre,int &index,int &key,int min,int max,int &n)
{
	if(index>=n)
		return NULL;
	node *root=NULL;
	if(key>min && key<max)
	{
		root=new node(key);
		index=index+1;
		if(index<n)
		{
			root->left=construct_bst_util(pre,index,pre[index],min,key,n);
			root->right=construct_bst_util(pre,index,pre[index],key,max,n);
		}
	}
	return root;
} 
node *construct_bst(int pre[],int n)
{
	int index=0;
	return constuct_bst_util(pre,index,pre[0],INT_MIN,INT_MAX,n);
}
//Method2 of above
node *BST_from_array(int pre[],int n)
{
	stack<node *> s;
	node *root=new node(pre[0]);
	s.push(root);
	node *temp;
	for(int i=1;i<n;i++)
	{
		temp=NULL;
		while(!s.empty() && pre[i]>s.top()->data)
		{
			temp=s.top();
			s.pop();
		}
		if(temp!=NULL)
		{
			temp->right=new node(pre[i]);	
			s.push(temp->right);
		}
		else
		{
			s.top()->left=new node(pre[i]);
			s.push(s.top()->left);
		}
	}
	return root;
}
bool isPresent_in_DLL(node *head,node *tail,int &sum)
{
	while(head!=tail)
	{
		int curr=head->data+tail->data;
		if(curr==sum)
			return true;
		else if(curr>sum)
			tail=tail->left;
		else
			head=head->right;
	}
	return false;
}
bool has_triplet(node *root)
{
	node *head=NULL;
	node *tail=NULL;
	convert_BST_DLL(root,head,tail);
	//If the head is itself not less than 0 then it won't have a triplet
	while(head->right!=tail && head->data<0)
	{
		if(isPresent_in_DLL(head->right,tail,-1*head->data))
			return true;
		else
			head=head->right;
	}
	return false;
}
bool hasOnlyOneChild(int pre[], int size)
{
    // Initialize min and max using last two elements
    int min, max;
    if (pre[size-1] > pre[size-2])
    {
        max = pre[size-1];
        min = pre[size-2]:
    }
    else
    {
        max = pre[size-2];
        min = pre[size-1];
    }
 
 
    // Every element must be either smaller than min or
    // greater than max
    for (int i=size-3; i>=0; i--)
    {
        if (pre[i] < min)
            min = pre[i];
        else if (pre[i] > max)
            max = pre[i];
        else
            return false;
    }
    return true;
}
int k_largest(node *root,int k)
{
	int result=-1;
	while(root)
	{
		if(root->rcount+1==k)
		{
			result=root->data;
			break;
		}
		else if(root->rcount < k)
		{
			k=k-root->rcount-1;	
			root=root->left;
		}
		else
			root=root->right;
	}
	return result;
}
void print_in_range(node *root,int k1,int k2)
{
	if(!root)
		return;
	if(root->data>k1)
		print_in_range(root->left,k1,k2);
	if(root->data>=k1 && root->data<=k2)
		cout<<root->data<<" ";
	if(root->data<=k2)
		print_in_range(root->right,k1,k2);
}
//Find the largest bst in a binary tree..
int largest_bst_util(node *root,int &min_val,int &max_val,int &size,bool &is_bst)
{
	if(!root)
	{
		is_bst=true;
		return 0;
	}
	int min=INT_MAX;
	bool left=false,right=false;
	int ls=0,rs=0;
	max_val=INT_MAX;
	ls=largest_bst_util(root->left,min_val,max_val,size,is_bst);
	if(is_bst && root->data>max_val)
		left=true;
	min=min_val;
	min_val=INT_MAX;
	rs=largest_bst_util(root->right,min_val,max_val,size,is_bst);
	if(is_bst && root->data < min_val)
		right=true;
	
	if(min < min_val)
		min_val=min;
	else if(root->data < min_val)
		min_val=root->data;
	if(root->data > max_val)
		max_val=root->data;
	if(left && right)
	{
		if(ls+rs+1 < size)
			size=ls+rs+1;
		return ls+rs+1;
	}
	else
	{
		is_bst=false;
		return 0;
	}
}
int largest_bst(node *root)
{
	int min=INT_MAX,max=INT_MIN,size=INT_MIN;
	bool is_bst=false;
	largest_bst_util(root,min,max,size,is_bst);
	return size;
}
node * remove_outside_range(node *root,int min,int max)
{
	if(root==NULL)
		return NULL;
	root->left=remove_outside_range(root->left,min,max);
	root->right=remove_outside_range(root->right,min,max);
	//Postorder for bottom up evaluation
	if(root->data<min)
	{
		//If this node is less than min then all its left subtree is..
		node *temp=root->right;
		delete root;
		return temp;
	}
	if(root->data > max)
	{
		//If this node is greater than max then all its right subtree is...
		node *temp=root->left;
		delete root;
		return temp;
	}
	//Unaffected..
	return root;
}
int main()
{
}
		
