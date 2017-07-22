#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

struct Node *SortedMerge(struct Node *a,struct Node *b);

void front_back_split(struct Node *head,struct Node **front,struct Node **back);

void Merge_sort(struct Node **head_ref)
{
	struct Node *head=*head_ref;
	if(head==NULL || head->next==NULL)
		return;
	struct Node *a,*b;
	front_back_split(head,&a,&b);
	Merge_sort(&a);
	Merge_sort(&b);
	head_ref=Sorted_merge(a,b);
}

void front_back_split(struct Node *head,struct Node **front,struct Node **back)
{
	struct Node *slow,*fast;
	if(head==NULL || head->next==NULL)
	{
		*front=head;
		*back=NULL;
		return;
	}
	slow=head;
	fast=head->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	*front=head;
	*back=slow->next;
	slow->next=NULL;
}
struct Node *SortedMerge(struct Node *a,struct Node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;	
	struct Node *res=NULL;
	if(a->data<=b->data)
	{
		res=a;
		res->next=SortedMerge(a->next,b);
	}
	else
	{
		res=b;
		res->next=SortedMerge(a,b->next);
	}
	return res;
}
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
  /* allocate node */
  struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
  
  /* put in the data  */
  new_node->data  = new_data;
  
  /* link the old list off the new node */
  new_node->next = (*head_ref);    
  
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
} 
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct Node* res = NULL;
  struct Node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  Merge_sort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);           
  
  getchar();
  return 0;
}
