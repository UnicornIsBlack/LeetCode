#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int findKthLargest(vector<int>& nums, int k)
	{
		for ( int i = 0; i < nums.size(); i++ )
		{
			for ( int j = 1; j < nums.size() - i; j++ )
			{
				if ( nums[j - 1] > nums[j] )
				{
					int tmp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = tmp;
				}
			}
			k--;
			if ( k == 0 )
				return nums[nums.size() - 1 - i];
		}
		return nums[0];
	}
};

int main()
{
	return 0;
}
