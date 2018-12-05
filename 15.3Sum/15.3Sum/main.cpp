#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int index0 = 0;
		vector<vector<int>> result;
		if ( nums.size() < 3 )
			return result;
		sort(nums.begin(), nums.end());
		while ( nums[index0] < 0 )
			index0++;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( nums[i] > 0 )
				break;
			if ( i > 0 && nums[i] == nums[i - 1] )
				continue;
			int sum = -nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while ( left < right )
			{
				if ( nums[left] + nums[right] == sum )
				{
					vector<int> three = { nums[i], nums[left], nums[right] };
					result.push_back(three);
					while ( left < right && nums[left++] == nums[left] ) {}
					while ( left < right && nums[right--] == nums[right] ) {}
				}
				else if ( nums[left] + nums[right] < sum )
				{
					while ( left < right && nums[left++] == nums[left] ) {}
				}
				else
				{
					while ( left < right && nums[right--] == nums[right] ) {}
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