#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;


class Solution
{
	public:
	string longestWord(vector<string>& words)
	{
		set<string> wordSet;
		for ( int i = 0; i < words.size(); i++ )
			wordSet.insert(words[i]);

		int length = 0;
		string word = "";

		for ( int i = 0; i < words.size(); i++ )
		{
			if ( words[i].size() > length || (words[i].size() == length&&words[i].compare(word) < 0) )
			{
				int len = words[i].size();
				while ( len > 0 )
				{
					set<string>::iterator it = wordSet.find(words[i].substr(0, len));
					if ( it != wordSet.end() )
						len--;
					else
						break;

				}
				if ( len == 0 )
				{
					length = words[i].size();
					word = words[i];
				}
			}
		}
		return word;
	}
};

int main()
{
	return 0;
}