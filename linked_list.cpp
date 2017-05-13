#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cassert>
using namespace std;
struct linkedlist{
	int data;
	linkedlist *link;
}typedef node;

// Maximum sum of Two Linked Lists
node *max_sum_list(node *a,node *b)
{
	node *curr1=a,*curr2=b,*prev1=a,*prev2=b,*result;
	while(curr1!=NULL && curr2!=NULL)
	{
		int sum1=0,sum2=0;
		while(curr1!=NULL && curr2!=NULL && curr1->data!=curr2->data)
		{
			if(curr1->data>curr2->data)
			{
				sum1+=curr1->data;
				curr1=curr1->next;
			}
			else
			{
				sum2+=curr2->data;
				curr2=curr2->next;
			}
		}
		while(curr1!=NULL)
		{
			sum1+=curr1->data;
			curr1=curr1->next;
		}
		while(curr2!=NULL)
		{
			sum2+=curr2->data;
			curr2=curr2->next;
		}
		if(prev1==a && prev2==b)
			result=(sum1>sum2)?prev1:prev2;
		else
		{
			if(sum1>sum2)
				prev2->next=prev1->next;
			else
				prev1->next=prev2->next;
		}
		prev1=curr1;
		prev2=curr2;
		if(curr1)
			curr1=curr1->next;
		if(curr2)
			curr2=curr2->next;		
	}
	return result;
}


void insert_first(node **a,int i)
{
	node *temp;
	temp=new node;
	assert(temp!=NULL);
	temp->data=i;
	temp->link=*a;
	*a=temp;
    //delete temp;
}
//Insertion Sort

node *Insertion_sort(node *head)
{
	node *result=NULL;
	while(head)
	{
		node *next=head->link;
		sorted_insert(&result,head);
		head=next;
	}
}
//Function that puts elements inside result list in sorted way..
void sorted_insert(node **head,node *new_node)
{
	if((*head)==NULL || head->data >= new_node->data)
	{
		new_node->link=*head;
		*head=new_node;
	}
	else
	{
		node *current=*head;
		while(current->link!=NULL && current->link->data < new_node->data)
			current=current->link;
		new_node->link=current->link;
		current->link=new_node;
	}
}

void delet_first(node **a)
{
	node *t=*a;
	*a=(*a)->link;
	delete t;
}

//Reverse the linked list
void reverse(node **head)
{
	node *p=*head,*next,*prev=NULL;
	while(p)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	*head=prev;
	//return head;
}

//Split the list into first and second halves
void split_half(node *head,node **front,node **back)
{
	if(head==NULL || head->link==NULL)
	{
		front=head;
		back=NULL;
		return;	
	}	
	node *slow=head,*fast=head->link;
	while(fast)
	{
		fast=fast->link;
		if(fast!=NULL)
		{
			slow=slow->link;
			fast=fast->link;
		}
	}
	*front=head;
	*back=slow->link;
	slow->link=NULL;
}
//Utility function to do merging
node *sorted_merge(node *a,node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	node *result;
	if(a->data<=b->data)
	{
		result=a;
		a->link=sorted_merge(a->link,b);
	}
	else
	{
		result=b;
		b->link=sorted_merge(a,b->link);
	}
	return result;
}
//Main function to do sorting
void merge_sort(node **head)
{
	if((*head)==NULL || (*head)->link==NULL)
		return ;
	
	node *fro=NULL,*bac=NULL;
	split_half(*head,&fro,&bac);
	merge_sort(&fro);
	merge_sort(&bac);
	*head=sorted_merge(fro,bac);
}

//Rearrane the List like ...
//	1->2->3->4 => 1->4->2->3
//	1->2->3->4->5 =>	1->5->2->4->3

void rearrange(node **head)
{
	node *slow=*head,*fast=slow->link;
	while(fast && fast->link)
	{
		slow=slow->link;
		fast=fast->link;
	}
	node *odd=*head,*even=slow->link;
	reverse(&even);
	node *empty=new node();
	empty->data=0;
	empty->link=NULL;
	*head=empty;
	node *temp=*head;
	while(odd || even)
	{
		if(odd)
		{
			temp->link=odd;
			odd=odd->link;
			temp=temp->link;
		}
		if(even)
		{
			temp->link=even;
			even=even->link;
			temp=temp->link;
		}
	}
	*head=empty->link;
}
void insert_loc(node **a,int o,int loc)
{
	node *temp,*t;
	temp=new node;
	t=*a;
	for(int i=1;i<loc-1;i++)
	{
		t=t->link;
	}
	temp->data=o;
	temp->link=t->link;
	t->link=temp;
	//delete temp;
}
void insert_last(node **a,int num)
{
	node *temp,*t;
	temp=new node;
	t=*a;
	while(t->link!=NULL)
	{
		t=t->link;
	}
	//t=t->link;
	temp->data=num;
	temp->link=NULL;
	t->link=temp;
    //delete temp;
}
void delet(node **a,int d)
{
	node *t;
	t=*a;
	while(t->link!=NULL)
	{
		if(t->data==d)
		{
			t->link=t->link->link;
			return;
		}
		else if(t->link->data==d&&t->link->link==NULL)
		{
			node *s=t->link;
			t->link=NULL;
			delete s;
			return;
		}
		else
			t=t->link;
	}
}
node *searchnfromlast(node **head,int n)
{
	node *temp=*head,*nthnode=NULL;
	for(int count=1;count<n;count++)
	{
		if(temp)
			temp=temp->link;
	}
	while(temp->link)
	{
		if(!nthnode)
			nthnode=*head;
		else
			nthnode=nthnode->link;
		temp=temp->link;
	}
	if(n==0)
		return nthnode->link;
	if(nthnode)
		return nthnode;
	return NULL;
}
node *LoopStart(node *head)
{
	node *slow=head,*fast=head;
	bool loop=false;
	while(slow && fast && fast->link)
	{
		slow=slow->link;
		fast=fast->link->link;
		if(slow==fast){
			loop=true;
			break;
		}
	}
	node *ptr1=fast,*ptr=slow;
	if(loop)
	{
		slow=head;
		while(slow!=fast)
		{
			slow=slow->link;
			fast=fast->link;
		}
		return slow;
	}
	int counter=0;
	if(loop)
	{
		ptr1=ptr1->link;
		while(ptr!=ptr1)
		{
			ptr=ptr->link;
			ptr1=ptr1->link;
			counter++;
		}
	}
	cout<<"\nLength of loop.."<<counter<<endl;
	return NULL;
}
node *findIntersect(node *head1,node *head2)
{
	int len1=0,len2=0,diff=0;
	node *t1=head1,*t2=head2;
	while(t1!=NULL)
	{
		len1++;
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		len2++;
		t2=t2->link;
	}
	node *start1,*start2;
	if(len1>=len2)
	{
		diff=len1-len2;
		start1=t1;
		start2=t2;
	}
	else
	{
		diff=len2-len1;
		start1=t2;
		start2=t1;
	}
	for(int i=0;i<diff;i++)
		start1=start1->link;
	while(start1 && start2)
	{
		if(start1==start2)
			return start1;
		start1=start1->link;
		start2=start2->link;
	}
	return NULL;
}
node *findmiddle(node *head)
{
	node *slw=head,*fst=head;
	while(fst && fst->link)
	{
		fst=fst->link->link;
		slw=slw->link;
	}
	return slw;
}
bool checkodd(node *head)
{
	while(head && head->link)
		head=head->link->link;
	if(!head)
		return true;
	return false;
}
node *mergelist(node *a,node *b)
{
	node *result=NULL;
	if(!a)
		return b;
	if(!b)
		return a;
	if(a->data<=b->data)
	{
		result=a;
		result->link=mergelist(a->link,b);
	}
	else
	{
		result=b;
		result->link=mergelist(a,b->link);
	}
	return result;
}
node * pairreverse(node *head)
{
	node *temp=NULL;
	if(head && head->link)
		return NULL;
	else
	{
		temp=head->link;
		head->link=head->link->link;
		temp->link=head;
		head=temp;
		head->link->link=pairreverse(head->link->link);
		return head;
	}
}
void splitCLL(node *head,node **head1,node **head2)
{
	node *slow=head,*fast=head;
	while(fast->link!=head && fast->link->link!=head)
	{
		slow=slow->link;
		fast=fast->link->link;
	}
	if(fast->link->link==head)
		fast=fast->link;
	*head1=head;
	*head2=slow->link;
	fast->link=slow->link;
	slow->link=head;
}
node *rev(node *head)
{
	node *prev=NULL,*next;
	while(head)
	{
		next=head->link;
		head->link=prev;
		prev=head;
		head=next;
	}
	return prev;
}
bool if_palindrome(node *head)
{
	node *slw=head,*fst=head;
	bool odd=false,sim=true;
	// Find the middle of the linked list
	while(fst && fst->link)
	{
		slw=slw->link;
		fst=fst->link->link;
	}
	//Odd nodes and even nodes finding to reverse second half
	if(!(fst->link))
		odd=true;
	// If its odd length leaving the median node compare the remaining 
	if(odd)
	{
		node *r=rev(slow->link);
		slow->link=r;	//Link the unlinked..
		while(head!=slow)
		{
			if(r!=NULL && r->data!=head->data)
			{
				sim=false;	
				break;
			}
			head=head->link;
			r=r->link;
		}	
	}
	//If its even length middle node is included...
	else
	{
		node *r=rev(slow);
		while(head!=slow)
		{
			if(r!=NULL && r->data!=head->data)
			{
				sim=false;	
				break;
			}
			head=head->link;
			r=r->link;
		
		}
	}
	return sim;	
}
node *Kplusone(int K,node *head)
{
	node *Kth;
	int i=0;
	if(!head)
		return head;
	for(i=0,Kth=head;Kth && (i<K);i++,Kth=Kth->link);
	if(i==K && Kth!=NULL)
		return Kth;
	return head->link;	//?
}
bool HasK(node *head,int K)
{
	int i=0;
	for(i=0;head && (i<K);i++,head=head->link);
	return i==K;
}
node *reverseKblocks(node *head,int K)
{
	node *curr=head,*prev,*next,*newHead;
	if(K==0||K==1)
		return head;
	if(HasK(head,K-1))
		newHead=Kplusone(K-1,head);
	else
		newHead=head;
	while(cur && HasK(curr,K))
	{
		temp=Kplusone(K,curr);
		i=0;
		while(i<K)
		{
			next=curr->link;
			curr->link=temp;
			temp=curr;
			curr=next;
			i++;
		}
	}
	return newHead;
}
//Here the linked lists represents numbers.Each node represents digits in descending power
node * add_lists(node *head1,node *head2)
{
	head1=rev(head1);
	head2=rev(head2);
	bool carry=false;
	node *newNode=new node;
	node *newHead=newNode;
	int s=0;
	if(head1 && head2)
	{
		s=head1->data+head2->data;
		if(s>=10)
		{
			s=s%10;
			carry=true;
		}
		newNode->data=s;
		newNode->link=NULL;
		head1=head1->link;
		head2=head2->link;
	}
	while(head1!=NULL && head2!=NULL)
	{
		newNode->link=new node;
		newNode=newNode->link;
		s=head1->data+head2->data;
		if(carry)
		{
			s+=1;
			carry=false;
		}
		if(s>=10)
		{
			s=s%10;
			carry=true;
		}
		newNode->data=s;
		newNode->link=NULL;
		head1=head1->link;
		head2=head2->link;
	}	
	while(head1!=NULL)
	{
		newNode->link=new node;
		newNode=newNode->link;
		s=head1->data;
		if(carry)
		{
			s+=1;
			carry=false;
		}
		if(s>=10)
		{
			s=s%10;
			carry=true;
		}
		newNode->data=s;
		newNode->link=NULL;
		head1=head1->link;
	}
	while(head2!=NULL)
	{
		newNode->link=new node;
		newNode=newNode->link;
		s=head2->data;
		if(carry)
		{
			s+=1;
			carry=false;
		}
		if(s>=10)
		{
			s=s%10;
			carry=true;
		}
		newNode->data=s;
		newNode->link=NULL;
		head2=head2->link;
	}
	newHead=rev(newHead);
	return newHead;
}

void alternate_lists(node **head1,node **head2)
{
	node *t1=*head1,*t2=*head2;
	while(t1 && t2)
	{
		node *temp=t1->link,*temp1=t2->link;
		t1->link=t2;
		t2->link=temp;
		t1=temp;
		t2=temp1;
	}
	*head2=t2;
}
void flattenList(node *head)
{
    /*Base case*/
    if (head == NULL)
       return;
 
    node *tmp;
 
    /* Find tail node of first level linked list */
    node *tail = head;
    while (tail->link != NULL)
        tail = tail->link;
 
    // One by one traverse through all nodes of first level
    // linked list till we reach the tail node
    node *cur = head;
    while (cur != tail)
    {
        // If current node has a child
        if (cur->child)
        {
            // then append the child at the end of current list
            tail->link = cur->child;
 
            // and update the tail to new last node
            tmp = cur->child;
            while (tmp->link)
                tmp = tmp->link;
            tail = tmp;
        }
 
        // Change current node
        cur = cur->link;
    }
}
int main()
{
	node *head;
	head=new node;
	head->data=12;
	head->link=NULL;
	insert_first(&head,5);
	insert_loc(&head,25,2);
	insert_first(&head,54);
	insert_last(&head,3);
	printf("\nLinked List..\n");
	node *f=head;
	while(f)
	{
		printf("%d\t",(f->data));
		f=f->link;
	}
	node *p=reverse(&head);
	cout<<"\nReversed Linked List...\n";
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->link;
	}
	node *t1=searchnfromlast(&head,1);
	if(t1!=NULL)
		cout<<"\n1st node from last: "<<t1->data;
	else
		cout<<"\nNo such node found..";
	printf("\nPair reversed Linked List..\n");
	node *t=pairreverse(head);
	while(t)
	{
		printf("%d\t",(t->data));
		t=t->link;
	}
	return 0;
}
