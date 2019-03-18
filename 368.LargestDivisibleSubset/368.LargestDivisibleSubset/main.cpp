#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> largestDivisibleSubset(vector<int>& nums)
	{
		quick(nums, 0, nums.size() - 1);
		vector<int> res;
		if ( nums.size() == 0 )
			return res;
		vector<int> index(nums.size(), -1);
		vector<int> dp(nums.size(), 1);
		int curMax = 1;
		int k = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			for ( int j = i + 1; j < nums.size(); j++ )
			{
				if ( nums[j] % nums[i] != 0 )
					continue;
				if ( dp[j] < dp[i] + 1 )
				{
					index[j] = i;
					dp[j] = dp[i] + 1;
				}
				if ( curMax < dp[j] )
				{
					curMax = dp[j];
					k = j;
				}
			}
		}
		while ( index[k] != -1 )
		{
			res.insert(res.begin(), nums[k]);
			k = index[k];
		}
		res.insert(res.begin(), nums[k]);
		return res;
	}

	void quick(vector<int>& nums, int low, int high)
	{
		if ( low > high )
			return;
		int key = nums[low];
		int i = low, j = high;
		while ( i < j )
		{
			while ( i < j && nums[j] >= key ) j--;
			while ( i < j && nums[i] <= key ) i++;
			if ( i < j )
			{
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}

		nums[low] = nums[i];
		nums[i] = key;
		quick(nums, low, i - 1);
		quick(nums, i + 1, high);
	}
};

int main()
{
	return 0;
}