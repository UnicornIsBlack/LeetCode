#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		vector<bool> word(s.size() + 1, false);
		word[0] = true;
		for ( int i = 1; i <= s.size(); i++ )
		{
			for ( int j = i - 1; j >= 0; j-- )
			{
				string end(s.begin() + j, s.begin() + i);
				if ( word[j] && isInList(end, wordDict) )
				{
					word[i] = true;
					break;
				}
			}
		}
		return word[s.size()];
	}
	bool isInList(string s, vector<string>& wordDict)
	{
		if ( s.size() == 0 )
			return true;
		for ( int i = 0; i < wordDict.size(); i++ )
		{
			if ( s == wordDict[i] )
				return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}