#include<iostream>
#include<string>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
struct TrieNode{
	TrieNode *child[26];
	bool isleaf;
};
TrieNode *getNode(void)
{
	TrieNode *n=new TrieNode;
	if(n)
	{
		n->isleaf=false;
		for(int i=0;i<26;i++)
			n->child[i]=NULL;
	}
	return n;
}
void insert(TrieNode *root,string key)
{
	int length=key.length();
	TrieNode *crawl=root;
	for(int level=0;level<length;level++)
	{
		int index=CHAR_TO_INDEX(key[level]);
		if(crawl->child[index]==NULL)
			crawl->child[index]=getNode();
		crawl=crawl->child[index];
	}
	crawl->isleaf=true;
}
int count_child(TrieNode *root,int &index)
{
	int count=0;
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			count++;
			index=i;	//For Longest common prefix only
		}
	}
	return count;
}
