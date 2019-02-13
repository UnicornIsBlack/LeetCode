#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode
{
	public:
	vector<TrieNode*> child;
	bool isWord;
	TrieNode() :child(26, nullptr), isWord(false) {};
	~TrieNode()
	{
		for ( auto c : child )
			delete c;
	}
};

class WordDictionary
{
	public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word)
	{
		TrieNode* p = root;
		for ( char c : word )
		{
			int index = c - 'a';
			if ( !p->child[index] )
				p->child[index] = new TrieNode();
			p = p->child[index];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word)
	{
		return match(root, word, 0);
	}

	bool match(TrieNode* node, string &word, int start)
	{
		if ( !node )
			return false;
		if ( start == word.size() )
			return node->isWord;
		int index = word[start] - 'a';
		if ( word[start] == '.' )
		{
			for ( const auto& child : node->child )
			{
				if ( match(child, word, start + 1) )
					return true;
			}
		}
		else
			return match(node->child[index], word, start + 1);
		return false;
	}
	private:
	TrieNode* root;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/
int main()
{
	return 0;
}