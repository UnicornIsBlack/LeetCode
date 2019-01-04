#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> res;
		int len = s.size();
		if ( len == 0 )
			return res;
		for ( int i = 1; i <= len; i++ )
		{
			string start(s.begin(), s.begin() + i);
			if ( !isPalindrome(start) )
				continue;
			string end(s.begin() + i, s.end());
			vector<vector<string>> results = partition(end);
			if ( results.size() == 0 )
			{
				vector<string> result;
				result.push_back(start);
				res.push_back(result);
			}
			else
			{
				for ( vector<string> result : results )
				{
					result.insert(result.begin(), start);
					res.push_back(result);
				}
			}
		}
		return res;
	}
	
	bool isPalindrome(string s)
	{
		int len = s.size();
		for ( int i = 0; i < len / 2; i++ )
		{
			if ( s[i] != s[len - 1 - i] )
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}