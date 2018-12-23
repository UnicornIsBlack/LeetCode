#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<int> allNums(n);
		for ( int i = 0; i < n; i++ )
		{
			allNums[i] = i + 1;
		}
		vector<int> currNums = {};
		return depthSearch(currNums, allNums, k);
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
	vector<int> nums = { 1, 2, 3, 4, 5 };
	vector<int> num(nums.begin() + 2, nums.end());
	for ( int i = 0; i < num.size(); i++ )
	{
		cout << num[i] << " ";
	}
	cout << endl;
	return 0;
}