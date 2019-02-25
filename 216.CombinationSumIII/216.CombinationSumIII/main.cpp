#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> results;
		vector<int> res;
		vector<int> nums(9);
		for ( int i = 0; i < nums.size(); i++ )
		{
			nums[i] = i + 1;
		}
		dfs(results, res, nums, k, n);
		return results;
	}

	void dfs(vector<vector<int>>& results, vector<int>& res, vector<int>& nums, int k, int n)
	{
		if ( k == 0 )
		{
			if ( n == 0 )
				results.push_back(res);
			return;
		}
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( nums[i] > n )
				break;
			res.push_back(nums[i]);
			vector<int> numsCopy(nums.begin() + i + 1, nums.end());
			dfs(results, res, numsCopy, k - 1, n - nums[i]);
			res.pop_back();
		}
	}
};

int main()
{
	return 0;
}