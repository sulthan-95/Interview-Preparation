#include<iostream>
#include<string>
using namespace std;
struct node{
	string data;
	node *left;
	node *right;
	node(string data)
	{
		node *root=new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
};
string alphabet[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
node * createtree(int index,string data,int *arr,int i,int n)
{
	if(index>26)
		return NULL;
	string s=data+alphabet[index];
	node *root=new node(s);
	if((n-i)>=0)
	{
		index=arr[i];
		root->left=createtree(index,s,arr,i+1,n);
		if((n-i)>1)
		{
			index=arr[i]*10+arr[i+1];
			root->right=createtree(index,s,arr,i+2,n);
		}
	}
	return root;
}
void print_tree(node *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<"\n";
		return;
	}
	print_tree(root->left);
	print_tree(root->right);
}

void print_interpret(int arr[],int n)
{
	node *root=createtree(0,"",arr,0,n-1);
	print_tree(root);
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	print_interpret(arr,n);
	return 0;
}
