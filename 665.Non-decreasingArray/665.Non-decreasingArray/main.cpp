#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
	bool checkPossibility(vector<int>& nums)
	{
		bool flag = true;
		bool isModify = false;
		for ( int i = 1; i < nums.size(); i++ )
		{
			if ( nums[i - 1]>nums[i] )
			{
				if ( isModify )
					return false;
				if ( i - 2 >= 0 && nums[i] < nums[i - 2] )
				{
					nums[i] = nums[i - 1];
				}
				else
					nums[i - 1] = nums[i];
				isModify = true;
			}
		}
		return flag;
	}
};

int main()
{
	return 0;
}