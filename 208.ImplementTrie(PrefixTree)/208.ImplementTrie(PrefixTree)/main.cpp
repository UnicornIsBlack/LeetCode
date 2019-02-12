#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
	public:
	/** Initialize your data structure here. */
	Trie()
	{

	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		this->words.push_back(word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		for ( string w : this->words )
		{
			if ( w.compare(word) == 0 )
				return true;
		}
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		for ( string w : this->words )
		{
			if ( prefix.size() > w.size() )
				continue;
			string pre = string(w.begin(), w.begin() + prefix.size());
			if ( pre.compare(prefix) == 0 )
				return true;
		}
		return false;
	}

	private:
	vector<string> words;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/

int main()
{
	return 0;
}