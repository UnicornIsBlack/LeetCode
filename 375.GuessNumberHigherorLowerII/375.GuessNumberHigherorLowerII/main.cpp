#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int getMoneyAmount(int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		int money = initDp(dp, 1, n);
		return money;
	}

	int initDp(vector<vector<int>>& dp, int m, int n)
	{
		if ( m >= n )
			return 0;
		if ( dp[m][n] != 0 )
			return dp[m][n];

		int minMoney = INT_MAX;

		for ( int i = m; i <= n; i++ )
		{
			int left = initDp(dp, m, i - 1);
			int right = initDp(dp, i + 1, n);

			int tmp = i + max(left, right);
			minMoney = min(minMoney, tmp);
		}
		dp[m][n] = minMoney;
		return dp[m][n];
	}
};

int main()
{
	return 0;
}