#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool canJump(vector<int>& nums)
	{
		vector<int> flag(nums.size(), 0);
		flag[0] = 1;
		for ( int i = 0; i < nums.size(); i++ )
		{
			for ( int j = 1; j <= nums[i] && i + j < nums.size(); j++ )
			{
				flag[i + j]++;
			}
		}
		if ( flag[nums.size() - 1] == 0 )
			return false;
		else
		{
			for ( int i = 0; i < flag.size(); i++ )
			{
				if ( flag[i] == 0 )
					return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}