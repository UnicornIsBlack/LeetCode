#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int len = nums.size();
		int low = 0;
		int high = len - 1;
		vector<int> result = { -1, -1 };
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			if ( nums[mid] == target )
			{
				int i = mid;
				for ( ; i >= 0; i-- )
				{
					if ( nums[i] != target )
						break;
				}
				result[0] = i + 1;
				i = mid;
				for ( ; i < len; i++ )
				{
					if ( nums[i] != target )
						break;
				}
				result[1] = i - 1;
				break;
			}
			if ( nums[mid] > target )
				high = mid - 1;
			else
				low = mid + 1;
		}
		return result;
	}
};

int main()
{
	return 0;
}