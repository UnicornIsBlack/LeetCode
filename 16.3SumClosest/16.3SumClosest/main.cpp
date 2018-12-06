#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		if ( nums.size() < 3 )
			return 0;
		sort(nums.begin(), nums.end());
		int closestSum = 0;
		int sub = INT_MAX;
		for ( int i = 0; i < nums.size() - 2; i++ )
		{
			int left = i + 1;
			int right = nums.size() - 1;
			while ( left < right )
			{
				int tmpSum = nums[i] + nums[left] + nums[right];
				if ( abs(tmpSum - target) <= sub )
				{
					closestSum = tmpSum;
					sub = abs(tmpSum - target);
				}
				if ( tmpSum == target )
					return tmpSum;
				else if ( tmpSum < target )
				{
					while ( left < right && nums[left++] == nums[left] ) {}
				}
				else
				{
					while ( left < right && nums[right--] == nums[right] ) {}
				}
			}
		}
		return closestSum;
	}
};

int main()
{

	return 0;
}