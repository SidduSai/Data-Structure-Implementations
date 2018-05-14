#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

class TrieNode
{
	public:
	TrieNode *children[ALPHABET_SIZE];
	bool isEnd;
	
	TrieNode()
	{
		isEnd = false;
		for(int i=0;i<ALPHABET_SIZE;i++)
			children[i] = NULL;
	}
};

void insert(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
			pCrawl->children[index] = new TrieNode();
			
		pCrawl = pCrawl->children[index];
	}
	
	pCrawl->isEnd = true;
}

bool search(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
			return false;
		else
			pCrawl = pCrawl->children[index];
	}
	if(pCrawl->isEnd == true)
		return true;
	else
		return false;
}

int main()
{
	TrieNode *root = new TrieNode();
	insert(root,"sai");
	insert(root,"saisid");
	insert(root,"patlolla");
	insert(root,"sidharth");
	insert(root,"reddy");
	cout<<search(root,"sai");
	cout<<search(root,"neeraja");
	cout<<search(root,"pat");
	cout<<search(root,"reddy");
}
