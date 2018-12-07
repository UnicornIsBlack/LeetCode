#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> result;
		if ( nums.size() < 4 )
			return result;
		sort(nums.begin(), nums.end());
		for ( int i = 0; i < nums.size() - 3; i++ )
		{
			// if ( nums[i] > target )
			// 	break;
			if ( i > 0 && nums[i] == nums[i - 1] )
				continue;
			int sum = target - nums[i];
			for ( int j = i + 1; j < nums.size() - 2; j++ )
			{
				// if ( nums[j] > sum )
				// 	break;
				if ( j > i + 1 && nums[j] == nums[j - 1] )
					continue;
				int sum2 = sum - nums[j];
				int left = j + 1;
				int right = nums.size() - 1;
				while ( left < right )
				{
					int sum3 = nums[left] + nums[right];
					if ( sum3 == sum2 )
					{
						vector<int> four = { nums[i], nums[j], nums[left], nums[right] };
						result.push_back(four);
						while ( left < right && nums[left++] == nums[left] ) {}
						while ( left < right && nums[right--] == nums[right] ) {}
					}
					else if ( sum3 < sum2 )
					{
						while ( left < right && nums[left++] == nums[left] ) {}
					}
					else
					{
						while ( left < right && nums[right--] == nums[right] ) {}
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}