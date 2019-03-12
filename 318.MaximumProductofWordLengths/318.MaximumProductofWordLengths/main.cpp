#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maxProduct(vector<string>& words)
	{
		vector<int> flags;
		for ( string word : words )
		{
			int flag = 0;
			for ( int i = 0; i < word.size(); i++ )
			{
				flag |= (1 << (word[i] - 'a'));
			}
			flags.push_back(flag);
		}
		int res = 0;
		for ( int i = 0; i < words.size(); i++ )
		{
			for ( int j = i + 1; j < words.size(); j++ )
			{
				if ( !(flags[i] & flags[j]) )
					res = max(res, int(words[i].size()*words[j].size()));
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}