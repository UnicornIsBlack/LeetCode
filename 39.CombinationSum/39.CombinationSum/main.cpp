#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> result;
		vector<int> tmp;
		dfs(candidates, result, tmp, target, 0);
		return result;
	}

	void dfs(vector<int>&candidates, vector<vector<int>>& res, vector<int> tmp, int target, int start)
	{
		if ( target == 0 )
		{
			res.push_back(tmp);
			return;
		}
		for ( int i = start; i < candidates.size(); i++ )
		{
			int tar = target - candidates[i];
			if ( tar >= 0 )
			{
				tmp.push_back(candidates[i]);
				dfs(candidates, res, tmp, tar, i);
				tmp.pop_back();
			}
		}
		return;
	}
};

int main()
{
	return 0;
}