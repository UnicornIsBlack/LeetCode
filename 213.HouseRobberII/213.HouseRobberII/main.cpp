#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int rob(vector<int>& nums)
	{
		if ( nums.size() == 0 )
			return 0;
		if ( nums.size() == 1 )
			return nums[0];
		if ( nums.size() == 2 )
			return max(nums[0], nums[1]);                  
		vector<int> notrob(nums.size(), 0); //not rob the 0 index house
		vector<int> rob(nums.size(), 0);	//rob the 0 index house
		rob[0] = nums[0];
		rob[1] = nums[0];
		rob[2] = nums[0];
		notrob[1] = nums[1];
		notrob[2] = max(nums[1], nums[2]);
		for ( int i = 3; i < nums.size(); i++ )
		{
			notrob[i] = max(notrob[i - 1], nums[i] + notrob[i - 2]);
			rob[i] = max(nums[i - 1] + rob[i - 3], rob[i - 1]);
		}
		return max(notrob[nums.size() - 1], rob[nums.size() - 1]);
	}
};

int main()
{
	return 0;
}