#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int findMin(vector<int>& nums)
	{
		int minNum = nums[0];
		int low = 0;
		int high = nums.size() - 1;
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			minNum = min(minNum, nums[mid]);
			if ( nums[mid] < nums[high] )
				high = mid - 1;
			else
			{
				minNum = min(minNum, nums[low]);
				low = mid + 1;
			}
		}
		return minNum;
	}
};

int main()
{
	return 0;
}