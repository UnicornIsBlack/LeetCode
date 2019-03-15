#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool increasingTriplet(vector<int>& nums)
	{
		vector<int> res;
		bool flag = dfs(res, nums);
		return flag;
	}

	bool dfs(vector<int>& res, vector<int>& nums)
	{
		if ( res.size() >= 3 )
			return true;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( res.size() == 0 )
				res.push_back(nums[i]);
			else
			{
				if ( nums[i] <= res.back() )
					continue;
				else
					res.push_back(nums[i]);
			}
			vector<int> copy(nums.begin() + i + 1, nums.end());
			if ( dfs(res, copy) )
				return true;
			res.pop_back();
		}
		return false;
	}
};

int main()
{
	return 0;
}