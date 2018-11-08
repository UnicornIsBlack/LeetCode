#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int lengthOfLongestSubstring(string s)
	{
		int map[256] = { 0 };
		int left = 0;
		int res = 0;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( map[s[i]] == 0 || map[s[i]] < left )
				res = max(res, i - left + 1);
			else
				left = map[s[i]];
			map[s[i]] = i + 1;
		}
		return res;
	}
};

int main()
{
	return 0;
}