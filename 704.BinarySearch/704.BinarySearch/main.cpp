#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
	public:
	int search(vector<int>& nums, int target)
	{
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;
		int index = -1;
		while ( low <= high )
		{
			mid = (low + high) / 2;
			if ( nums[mid] == target )
			{
				index = mid;
				break;
			}
			else if ( nums[mid] < target )
				low = mid + 1;
			else if ( nums[mid] > target )
				high = mid - 1;
		}
		return index;
	}
};

int main()
{
	return 0;
}