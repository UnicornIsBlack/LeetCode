#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
	public:
	int lengthOfLIS(vector<int>& nums)
	{
		vector<int> lis(nums.size(), 0);
		if ( nums.size() == 0 )
			return 0;
		lis[0] = 1;
		int res = 0;
		for ( int i = 1; i < nums.size(); i++ )
		{
			int longest = 0;
			for ( int j = i - 1; j >= 0; j-- )
			{
				if ( nums[j] < nums[i] )
					longest = max(lis[j], longest);
			}
			lis[i] = longest + 1;
			res = max(res, lis[i]);
		}
		return res;
	}
};


int main()
{
	return 0;
}