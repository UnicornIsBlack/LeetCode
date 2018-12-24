#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int removeDuplicates(vector<int>& nums)
	{
		if ( nums.size() <= 2 )
			return nums.size();
		int count = 1;
		for ( int i = 1; i < nums.size(); i++ )
		{
			if ( nums[i] == nums[i - 1] )
			{
				count++;
				if ( count > 2 )
					nums.erase(nums.begin() + i--);
			}
			else
				count = 1;
		}
		return nums.size();
	}
};

int main()
{
	return 0;
}