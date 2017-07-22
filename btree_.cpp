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
	btree *next;
}typedef node;
struct dll{
	int data;
	dll *prev;
	dll *next;
	dll(int data)
	{
		dll->data=data;
		dll->prev=NULL;
		dll->next=NULL;
	}
}; 
void vs_util(node *root,dll *head)
{
	dll.data+=root->data;
	if(root->left)
	{
		if(head->prev==NULL)
		{
			head->prev=new node(0);
			head->prev->next=head;
		}
		vs_util(root->left,head->prev);
	}
	if(root->right)
	{
		if(head->next==NULL)
		{
			head->next=new node(0);
			head->next->prev=head;
		}
		vs_util(root->right,head->next);
	}
}
//A function that returns maximum sum between two leaves
//A post order traversal is done since max should be found in bottom up manner
int max_path_sum_util(node *root,int &maxi)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->data;
	int le_sum=max_path_sum_util(root->left,maxi);
	int ri_sum=max_path_sum_util(root->right,maxi);
	if(root->left && root->right)
	{
		maxi=max(maxi,le_sum+ri_sum+root->data);
		return max(le_sum,ri_sum)+root->data;
	}
	return (root->left)?ri_sum+root->data:le_sum+root->data;
}
int max_path_sum(node *root)
{
	if(root==NULL)
		return 0;
	int maxi=INT_MIN;
	max_path_sum_util(root,maxi);
	return maxi;
}
//This is one of the examples of tree travesals while left node is visited first and right node gets visited for each top of the stack
void print_ancestors(node *root,int key)
{
	if(root==NULL)
		return;
	stack<node *> s1;
	while(1)
	{
		while(root && root->data !=key)
		{
			s1.push(root);
			root=root->right;
		}
		if(root && root->data==key)
			break;
		//If top of the stack is a leaf node
		if(s1.top()->left==NULL)
		{
			root=s1.top();
			s1.pop();
			//Check for infinite loop run in tree
			while(!s1.empty()&&s1.top()->left==root)
			{
				root=s1.top();
				s1.pop();
			}
		}
		root=s1.empty()?NULL:s1.top()->left;
	}
	while(!s1.empty())
	{
		cout<<s1.top()->data<<" ";
		s1.pop();
	}
}
int post_order_nearest(node *root,int key,bool &visited,int &total_min)
{
	if(root==NULL)
		return 10000;
	if(root->left==NULL && root->right==NULL)
	{
		if(root->key==key)
			total_min=0;
		return 1;
	}
	int left_min,right_min,current_min;
	bool left_visit=false;
	left_min=post_order_nearest(root->left,key,visited,total_min);
	if(visited==true)
		left_visit=true;
	right_min=post_order_nearest(root->right,key,visited,total_min);
	current_min=(leftmin<rightmin)?leftmin:rightmin;
	
	if(root->key==key)
	{
		total_min=(total_min<current_min)?total_min:current_min;
		visited=true;
		return 1;	//If the key gets visited and total_min gets updated distance from key to its PARENT is only needed for other subtree
	}
	if(visited)
	{
		total_min=total_min<(left_min+right_min)?total_min:left_min+right_min;
		if(left_visit)
			return left_min+1;
		else
			return right_min+1;
	}	
	return current_min+1;
}
int find_closest_leaf(node *root,int key)
{
	if(root==NULL)
		return -1;
	int total_min=10000;
	bool visited=false;
	post_order_nearest(root,key,visited,total_min)
	return total_min;
}	
void reverseLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}
//Print the nodes at k distance from leaves
void kdist_from_util(node *root,int k,int *path,bool *visited,int len)
{
	if(root==NULL)
		return;	
	path[len]=root->data;
	visited[len]=false;
	len++;
	
	if(root->left==NULL && root->right==NULL && len-k-1>=0 && !visited[len-k-1])
	{
		cout<<path[len-k-1]<<endl;
		visited[len-k-1]=true;
		return;
	}
	kdist_from_util(root->left,k,path,visited,len+1);
	kdist_from_util(root->right,k,path,visited,len+1);
}
void Kdist_from_leaf(node *root,int k)
{
	int path[20];
	bool visited[20]={false};
	kdist_util(root,k,path,visited,0);
}
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}	
void vertical_sum_DLL(node *root)
{
	dll head=new dll(0);
	vs_util(root,head);
	while(head->prev!=NULL)
		head=head->prev;
	while(head)
	{
		cout<<head->data;
		head=head->next;
	}
}
//Find distance between 2 nodes n1 and n2
node * find_dist_util(node *root,int &n1,int &n2,int &d1,int &d2,int &dist,int lvl)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1)
	{
		d1=lvl;
		return root;
	}
	if(root->data==n2)
	{
		d2=lvl;
		return root;
	}
	node *left_lca=find_dist_util(root->left,n1,n2,d1,d2,dist,lvl+1);
	node *right_lca=find_dist_util(root->right,n1,n2,d1,d2,dist,lvl+1);
	
	if(left_lca && right_lca)
	{
		dist=d1+d2-2*lvl;
		return root;
	}
	
	return (left_lca!=NULL)?left_lca:right_lca;
}

int find_level(node *root,int key,int lvl)
{
	if(root==NULL)
		return -1;
	if(root->data==key)
		return lvl;
	int l=find_level(root->left,key,lvl+1);
	return (l!=-1)?l:find_level(root->right,key,lvl+1);
}

int find_distance(node *root,int n1,int n2)
{
	int d1=-1,d2=-1,dist=-1;
	node *lca=find_dist_util(root,n1,n2,d1,d2,dist,1);
	if(d1!=-1 && d2!=-1)
		return dist;
	if(d1!=-1)
	{
		dist=find_level(lca,n2,0);
		return dist;
	}
	if(d2!=-1)
	{
		dist=find_level(lca,n1,0);
		return dist;
	}
	return -1;
}
//Reverse Alternate levels in a binary tree
void do_inorder(node *root,int &n,int *in,int lvl,bool &store)
{
	if(root)
	{	
		store_inorder(root->left,n,in,lvl+1,store);
		if(lvl & 1)
		{
			if(store)
				in[n++]=root->data;
			else
				root->data=in[--n];
		}
		store_inorder(root->right,n,in,lvl+1,store);
	}
}
void reverse_odd_level(node *root)
{
	bool store=true;
	int *in=new int[100];
	int n=0;
	do_inorder(root,0,in,n,store);
	do_inorder(root,0,in,n,!store);
}
//Print the vertical order
void find_min_max(node *root,int &min,int &max,int level)
{
	if(root==NULL)
		return;
	if(level<min)
		min=level;
	else if(level>max)
		max=level;
	find_min_max(root->left,min,max,level-1);
	find_min_max(root->right,min,max,level+1);
}
void vertical(node *root,vector<vector<int> > &v,int index)
{
	if(root==NULL)
		return;
	print_vertical(root->left,v,index-1);
	v[index].push_back(root->data);
	print_vertical(root->right,v,index+1);
}
void print_vertical(node *root)
{
	int min=0,max=0;
	find_min_max(root,min,max,0);
	int n=max-min;
	vector<vectot<int> > v;
	vertical(root,v,-min);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
//Populate inorder successor in reverse inorder
void inorder_succ(node *root)
{
	static node *next=NULL;
	if(!root)
		return;
	inorder_succ(root->right);
	root->next=next;
	next=root;
	inorder(root->left);
}
node * newNode(int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->next=NULL;
	return newnode;
}
//Utilies for Building trees from Level Order and Inorder Traversal
int search(int *arr,const int &start,const int &end,int &value)
{
	for(int i=start;i<=end;i++)
	{
		if(arr[i]==value)
			return i;
	}
	return -1;
}
void extract_level(int *in,int *level,int m,int n)
{
	int *newlevel=new int[m],i=0;
	for(int j=0;j<n;j++)
	{
		if(search(in,0,m-1,level[j])==-1)
			newlevel[i]=level[j],i++;
	}
	return newlevel;
}
//Build tree from Level Order and Inorder traversal
node *build_tree(int *in,int *level,int ins,int ine,int n)
{
	if(ins>ine)
		return NULL;
	node *root=new node(level[0]);
	if(ins==ine)
		return root;
	//Find the index of root in Inorder array
	int index=search(in,ins,ine,level[0]);
	//Make the left side of Index as left level array
	int *llevel=extract_level(in,level,index,n);
	//Make the right side as right level array
	int *rlevel=extract_level(in+index+1,level,n-index-1,n);
	//Build Tree for left subtree
	root->left=build_tree(in,llevel,ins,index-1,n);
	//Build tree for right subtree
	root->right=build_tree(in,rlevel,index+1,ine,n);
	
	delete [] llevel;
	delete [] rlevel;
	
	return root;
}
void mirror_tree(node *root)
{
	if(root==NULL)
		return;
	mirror(root->left);
	mirror(root->right);
	node *temp=root->left;
	root->left=root->right;
	root->right=temp;
}
//BUild a special bin tree from Inorder Trvaersal
int find_max(int *arr,int start,int end)
{
	int max=arr[start];
	int in=start;
	for(int i=start+1;i<=end;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			in=i;
		}
	}
	return in;
}
node * build_spt(int *inarr,int start,int end)
{
	if(start>end)
		return NULL;	
	int index=find_max(inarr,start,end);
	node *root;
	root=new node;
	root->data=inarr[index];
	root->left=NULL;
	root->right=NULL;
	if(start==end)
		return root;
	root->left=build_spt(inarr,start,index-1);
	root->right=build_spt(inarr,index+1,end);
	return root;
}
void special_bt(node **root,int *inordr,int n)
{
	*root=build_spt(inorder,0,n-1);
}
bool print_ancestors(node *root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	if(print_ancestors(root->left,data) || print_ancestors(root->right,data)
	{
		cout<<root->data<<endl;
		return true;
	}
	return false;
}
//
//Connect nodes at same level
void connect_nodes(node *root)
{
	if(!root)
		return;
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		if(root==NULL)
		{
			if(!q.empty())
				q.push(NULL);
		}
		else 
		{
			if(!q.empty())
				root->next=q.front();
			else
				root->next=NULL;
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
	}
}
//Find the depth of deepest odd level leaf node
void find_deep(Node *root,int level,int *depth)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		if(level%2!=0)
		{
			if(level>(*depth))
				*depth=level;
		}
	}
	else
	{	
		find_deep(root->left,level+1,depth);
		find_deep(root->right,level+1,depth);
	}
}
int deep_odd(Node *root)
{	
	if(root==NULL)
		return 0;
	int depth=0;
	find_deep(root,1,&depth);
	return depth;
}
// Recursive function with preorder traversal for connect next
void connect_next(node *root)
{
	if(!root)
		return;
	root->next=NULL;
	connect_recur(root);
}
// Helper functions
node *get_next(node *root)
{
	node *temp=root->next;
	while(!temp)
	{
		if(temp->left!=NULL)
			return temp->left;
		if(temp->right!=NULL)
			return temp->right;
		temp=temp->next;
	}
	return NULL;
}
void connect_recur(node *root)
{
	if(!root)
		return;
	if(root->next!=NULL)
		connect_recur(root->next);
	if(root->left)
	{
		if(root->right)
		{
			root->left->next=root->right;
			root->right->next=get_next(root);
		}
		else
			root->left->next=get_next(root);
		connect_recur(root->left);
	}
	else if(root->right)
	{
		root->right->next=get_next(root);
		connect_recur(root->right);
	}
	else
		connect_recur(get_next(root));
}
//Find the sum of number formed by root to leaf paths
void find_sum(node *root,int current_sum,int &sum)
{
	if(root==NULL)
		return;
	current_sum=current_sum*10+root->data;
	if(root->left==NULL && root->right==NULL)
		sum+=current_sum;
	else
	{
		find_sum(root->left,current_sum,sum);
		find_sum(root->right,current_sum,sum);
	}
}
int sum_finder(node *root)
{
	if(root==NULL)
		return 0;
	int sum=0;
	find_sum(root,0,sum);
	return sum;
}
//Whether a binary tree is complete or not
bool isComplete(btree *root)
{
	queue<btree *> q;
	bool flag=false;
	if(!root)
		return;
	q.push(root);
	while(!root)
	{
		root=q.front();
		q.pop();
		if(root->left)
		{
			if(flag)	//If there is a non full node already it is incomplete
				return false;
			q.push(root->left);
		}
		else			//If a half node/leaf node comes no more child node alowed
			flag=true;
		if(root->right)
		{
			if(flag)	
				return false;
			q.push(root->right);
		}
		else
			flag=true;
	}
	return true;
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
//Find LCA for 2 nodes in a binary tree
node *find_lca_util(node *root,int n1,int n2,bool &v1,bool &v2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1)
	{
		v1=true;
		return root;
	}
	if(root->data==n2)
	{
		v2=true;
		return root;
	}
	node *left_lca=find_lca_util(root->left,n1,n2,v1,v2);
	node *right_lca=find_lca_util(root->right,n1,n2,v1,v2);
	if(left_lca && right_lca)
		return root;
	//Atleast one of the left or right lca must be set
	return (left_lca!=NULL)?left_lca:right_lca;
}
bool find(node *root,int k)
{
	if(root==NULL)
		return false;
	if(root->data==k || find(root->left,k) || find(root->right,k))
		return true;
	return false;
}
node *find_lca(node *root,int n1,int n2)
{
	if(root==NULL)
		return false;
	bool v1=false,v2=false;
	node *lca=find_lca_util(root,n1,n2,v1,v2);
	if(v1 && v2 || v1 && find(lca,n1) || v2 && find(lca,n2))
		return lca;
	return NULL;
}
//Whether a binary tree is foldable or not
bool isf_util(node *root1,node *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return isf_util(root1->left,root2->right)  && isf_util(root1->right,root2->left);
}
bool is_foldable(node *root)
{
	if(root==NULL)
		return true;
	return isf_util(root->left,root->right);
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
//This functions make the node's data same as that of sum of children
void child_sum_tree(node *root)
{
	int left_data=0,right_data=0;
	if(!root)
		return;
	else
	{
		child_sum_tree(root->left);
		child_sum_tree(root->right);
		if(root->left!=NULL)
			left_data=root->left->data;
		if(root->right!=NULL)
			right_data=root->right->data;
		int diff=left_data+right_data-diff;
		if(diff>0)
			root->data+=diff;
		else if(diff<0)
			increment(root,-diff);
	}
}
void increment(node *root,int diff)
{
	if(root->left)
	{
		root->left->data+=diff;
		increment(root->left);
	}
	else if(root->right)
	{
		root->right->data+=diff;
		increment(root->right);
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

bool isIsomophic(node *root1,node *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	if(root1->data!=root2->data)
		return false;
	return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)) || (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}
bool AreMirror(btree *root1,btree *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return root1->data==root2->data && AreMirror(root1->left,root2->right) && AreMirror(root1->right,root2->left);
}	

node *btr2dlutil(node *root)
{
	if(!root)
		return NULL;
	if(root->left)
	{
		node *pred=btr2dlutil(root->left);
		for(;pred->right!=NULL;pred=pred->right);
		pred->right=root;
		root->left=pred;
	}
	if(root->right)
	{
		node *succ=btr2dlutil(root->right);
		for(;succ->left!=NULL;succ=succ->left);
		succ->left=root;
		root->right=succ;
	}
	return root;
}
node *bintree2dll(node *root)
{
	if(!root)
		return NULL;
	node *root=btr2dllutil(node *root);
	while(root->left)
		root=root->left;
	return root;
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
void postordernonrec(node *root)
{
	stack<node *> S;
	do{
		while(root)
		{
			if(root->right)
				S.push(root->right);
			S.push(root);
			root=root->left;
		}
		root=S.top();
		S.pop();
		if(root->right && S.top()==root->right)
		{
			S.pop();
			S.push(root);
			root=root->right;
		}
		else
		{
			cout<<root->data<<" ";
			root=NULL;
		}
	}while(!S.empty());
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
