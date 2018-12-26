#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		set<vector<int>> resSet;
		vector<vector<int>> res;
		int k = 0;
		while ( k <= nums.size() )
		{
			vector<int> currNums = {};
			vector<vector<int>> result = depthSearch(currNums, nums, k);
			for ( int i = 0; i < result.size(); i++ )
			{
				resSet.insert(result[i]);
			}
			k++;
		}
		set<vector<int>>::iterator it;
		for ( it = resSet.begin(); it != resSet.end(); it++ )
		{
			res.push_back(*it);
		}
		return res;
	}
	vector<vector<int>> depthSearch(vector<int>& currNums, vector<int>& allNums, int k)
	{
		vector<vector<int>> results;
		if ( k == 0 )
		{
			results.push_back(currNums);
			return results;
		}
		if ( k == 1 )
		{
			for ( int i = 0; i < allNums.size(); i++ )
			{
				currNums.push_back(allNums[i]);
				results.push_back(currNums);
				currNums.pop_back();
			}
			return results;
		}
		for ( int i = 0; i < allNums.size(); i++ )
		{
			currNums.push_back(allNums[i]);
			vector<int> nums(allNums.begin() + i + 1, allNums.end());
			vector<vector<int>> result;
			result = depthSearch(currNums, nums, k - 1);
			for ( int j = 0; j < result.size(); j++ )
			{
				results.push_back(result[j]);
			}
			currNums.pop_back();
		}
		return results;
	}

};

int main()
{
	return 0;
}