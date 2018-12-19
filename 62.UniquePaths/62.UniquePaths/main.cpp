#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> result(n, vector<int>(m, 1));
		for ( int i = 1; i < n; i++ )
		{
			for ( int j = 1; j < m; j++ )
			{
				result[i][j] = result[i - 1][j] + result[i][j - 1];
			}
		}
		return result[n - 1][m - 1];
	}

};

int main()
{
	return 0;
}