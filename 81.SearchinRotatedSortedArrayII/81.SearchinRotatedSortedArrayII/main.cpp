#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
	bool search(vector<int>& nums, int target)
	{
		if ( nums.size() == 0 )
			return false;
		int low = 0;
		int high = nums.size() - 1;
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			if ( nums[mid] == target )
				return true;
			if ( nums[low] < nums[mid] )
			{
				if ( nums[low] <= target && nums[mid] > target )
					high = mid - 1;
				else
					low = mid + 1;
			}
			else if ( nums[low] > nums[mid] )
			{
				if ( nums[mid] < target && nums[high] >= target )
					low = mid + 1;
				else
					high = mid - 1;
			}
			else
				low++;
		}
		return false;
	}
};

int main()
{
	return 0;
}