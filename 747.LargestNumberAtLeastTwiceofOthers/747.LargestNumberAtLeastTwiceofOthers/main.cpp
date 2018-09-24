#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
	public:
	int dominantIndex(vector<int>& nums)
	{
		if ( nums.size() == 1 )
			return 0;
		int indexMax = nums[0] >= nums[1] ? 0 : 1;
		int indexSecMax = indexMax == 0 ? 1 : 0;
		for ( int i = 2; i < nums.size(); i++ )
		{
			if ( nums[i] < nums[indexSecMax] )
				continue;
			else if ( nums[i] > nums[indexMax] )
			{
				indexSecMax = indexMax;
				indexMax = i;
			}
			else
				indexSecMax = i;
		}
		if ( nums[indexMax] >= (nums[indexSecMax] * 2) )
			return indexMax;
		return -1;
	}
};

int main()
{
	return 0;
}