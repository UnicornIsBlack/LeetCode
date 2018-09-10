#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
	public:
	int findLengthOfLCIS(vector<int>& nums)
	{
		if ( nums.size() == 0 )
			return 0;
		int maxLen = 0;
		int len = 1;
		for ( int i = 1; i < nums.size(); i++ )
		{
			if ( nums[i] > nums[i - 1] )
			{
				len++;
			}
			else
			{
				maxLen = max(maxLen, len);
				len = 1;
			}
		}
		maxLen = max(maxLen, len);
		return maxLen;
	}
};

int main()
{
	return 0;
}