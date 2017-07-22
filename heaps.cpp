#include<iostream>
using namespace std;
struct Heap{
	int *array;
	int count;
	int size;
	bool type;
};
Heap *Create_Heap(int size,bool type)
{
	Heap *h=new Heap;
	h->count=0;
	h->size=size;
	h->type=type;
	h->array=new int[h->size];
	return h;
}
int Parent(int i)
{
	if(i<=0 || i>h->count)
		return -1;
	return (i-1)/2;
}
int left(int i)
{
	int l=2*i+1;
	if(l>=h->count)
		return -1;
	return l;
}
int right(int i)
{
        int r=2*i+2;
        if(r>=h->count)
                return -1;
        return r;
}
int get_max(Heap *h)
{
	if(h->count==0)
		return -1;
	return h->array[0];
}
void Percolate_down(Heap *h,int i)
{
	int l,r,max,temp;
	l=left(i);
	r=right(i);
	if(l!=-1 && h->array[l]>h->array[i])
		max=l;
	else
		max=i;
	if(r!=-1 && h->array[r]>h->array[max])
		max=r;
	if(max!=i)
	{
		temp=h->array[max];
		h->array[max]=h->array[i];
		h->array[i]=temp;

		Percolate_down(h,max);
	}
}
void Delete_max(Heap *h)
{
	int data=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count-=1;
	Percolate_down(h,0);
	return data;
}
void Resize_Heap(Heap *h)
{
	int *old_array=h->array;
	h->capacity*=2;
	h->array=new int[h->capacity];
	for(int i=0;i<h->count;i++)
		h->array[i]=old_array[i];
	delete old_array;
}
void Insert(Heap *h,int data)
{
	if(h->count==h->capacity)
		Resize_Heap(h);
	h->array[h->count++]=data;
	int i=h->count-1;
	while(i>=0 && data>h->array[(i-1)/2];
	{
		h->array[i]=h->array[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i]=data;
}
void Build_Heap(Heap *h,int A[],int n)
{
	if(h==NULL)
		return;
	while(n > h->capacity)
		Resize_Heap(h);
	for(int i=0;i<n;i++)
		h->array[i]=A[i];
	h->count=n;
	for(i=(n-1)/2;i>=0;i--)
		Percolate_down(h,i);
}
void Destroy_Heap(Heap *h)
{
	if(h==NULL)
		return;
	delete h->array;
	delete h;
	h=NULL;
}
void HeapSort(int A[],int n)
{
	Heap *h=Create_Heap(n,false);
	int old_size,i,temp;
	Build_Heap(h,A,n);
	old_size=h->count;
	for(i=n-1;i>=0;i--)
	{
		int temp=h->array[0];
		h->array[0]=h->array[count-1];
		h->array[h->count-1]=temp;
		h->count--;
		Percolate_down(h,0);
	}
	h->count=old_size;
}
//Find Min in max heap
void get_min(Heap *h)
{
	int Min=9999;
	for(int i=(h->count+1)/2;i<h->count;i++)
	{
		if(h->array[i]<Min)
			Min=h->array[i];
	}
	return Min;
}
			
