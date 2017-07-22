#include "Trie.cpp"
string walk_trie(TrieNode *root)
{
	TrieNode *crawl=root;
	int count=0,index=0;
	string s1;
	while(count_child(crawl,index)==1 && crawl->isleaf==false)
	{
		crawl=crawl->child[index];
		s1.push_back('a'+index);
	}
	return s1;
}
void construct_trie(TrieNode *root,string arr[],int n)
{
	for(int i=0;i<n;i++)
		insert(root,arr[i]);
}
string lcp(string arr[],int n)
{
	TrieNode *root=getNode();
	construct_trie(root,arr,n);
	return walk_trie(root);
}
int main()
{
	string arr[4]={"geeksforgeeks","geeks","geek","geezer"};
	cout<<lcp(arr,4)<<endl;
	return 0;
}
