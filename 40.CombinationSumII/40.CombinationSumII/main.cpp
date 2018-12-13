#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int>> result;
		vector<int> tmp;
		set<vector<int>> resSet;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, resSet, tmp, target, 0);
		set<vector<int>>::iterator it;
		for ( it = resSet.begin(); it != resSet.end(); it++ )
		{
			result.push_back(*it);
		}
		return result;
	}

	void dfs(vector<int>& candidates, set<vector<int>>& resSet, vector<int> tmp, int target, int start)
	{
		if ( target == 0 )
		{
			resSet.insert(tmp);
			return;
		}
		for ( int i = start; i < candidates.size(); i++ )
		{
			int tar = target - candidates[i];
			if ( tar >= 0 )
			{
				tmp.push_back(candidates[i]);
				dfs(candidates, resSet, tmp, tar, i + 1);
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