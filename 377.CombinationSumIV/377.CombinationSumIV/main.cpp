#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int> res(target + 1, 0);
		res[0] = 1;
		for ( int i = 1; i <= target; i++ )
		{
			int sum = 0;
			for ( int j = 0; j < nums.size(); j++ )
			{
				if ( nums[j] > i )
					continue;
				sum += res[i - nums[j]];
			}
			res[i] = sum;
		}
		return res[target];
	}
};

int main()
{
	return 0;
}