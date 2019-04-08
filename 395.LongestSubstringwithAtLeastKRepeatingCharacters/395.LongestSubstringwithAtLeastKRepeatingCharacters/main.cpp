#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int longestSubstring(string s, int k)
	{
		return maxSub(s, k, 0, s.size() - 1);
	}

	int maxSub(string s, int k, int start, int end)
	{
		if ( start > end )
			return 0;
		vector<int> nums(26, 0);
		for ( int i = start; i <= end; i++ )
			nums[s[i] - 'a']++;
		for ( int i = 0; i < 26; i++ )
		{
			if ( nums[i] > 0 && nums[i] < k )
			{
				int index = s.find(i + 'a', start);
				return max(maxSub(s, k, start, index - 1), maxSub(s, k, index + 1, end));
			}
		}
		return end - start + 1;
	}
};

int main()
{
	return 0;
}