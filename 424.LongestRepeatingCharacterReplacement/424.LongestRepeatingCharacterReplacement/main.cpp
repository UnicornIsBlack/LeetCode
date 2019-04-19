#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int characterReplacement(string s, int k)
	{
		vector<int> chars(26, 0);
		int start = 0;
		int maxNum = 0;
		int res = 0;
		for ( int i = 0; i < s.size(); i++ )
		{
			maxNum = max(maxNum, ++chars[s[i] - 'A']);
			int len = i - start + 1;
			if ( len - maxNum > k )
			{
				maxNum = max(maxNum, --chars[s[start] - 'A']);
				start++;
			}
			else
				res = max(res, len);
		}
		return res;
};

int main()
{
	return 0;
}