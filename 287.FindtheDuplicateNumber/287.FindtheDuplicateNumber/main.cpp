#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int findDuplicate(vector<int>& nums)
	{
		int low = 1, high = nums.size() - 1;
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			int small = 0;
			int big = 0;
			int equal = 0;
			for ( int i = 0; i < nums.size(); i++ )
			{
				if ( nums[i] < low || nums[i] > high )
					continue;
				if ( nums[i] < mid )
					small++;
				else if ( nums[i] == mid )
					equal++;
				else
					big++;
			}
			if ( equal >= 2 )
				return mid;
			if ( small + equal > big )
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
};

int main()
{
	return 0;
}