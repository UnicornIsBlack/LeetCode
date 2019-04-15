#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool canPartition(vector<int>& nums)
	{

		int target = accumulate(nums.begin(), nums.end(), 0);
		if ( target % 2 == 1 )
			return false;
		target >>= 1;
		vector<bool> flag(target + 1, false);
		flag[0] = true;
		
		for ( int num : nums )
		{
			for ( int i = target; i >= num; i-- )
				flag[i] = flag[i] | flag[i - num];
		}
		return flag[target];

	}
};

int main()
{
	return 0;
}