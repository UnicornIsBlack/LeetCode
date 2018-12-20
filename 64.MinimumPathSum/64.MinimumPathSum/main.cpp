#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int row = grid.size();
		if ( row == 0 )
			return 0;
		int col = grid[0].size();
		vector<vector<int>> res(row, vector<int>(col, 0));
		res[0][0] = grid[0][0];
		for ( int i = 1; i < row; i++ )
		{
			res[i][0] = grid[i][0] + res[i - 1][0];
		}
		for ( int i = 1; i < col; i++ )
		{
			res[0][i] = grid[0][i] + res[0][i - 1];
		}
		for ( int i = 1; i < row; i++ )
		{
			for ( int j = 1; j < col; j++ )
			{
				int right = res[i][j - 1] + grid[i][j];
				int down = res[i - 1][j] + grid[i][j];
				res[i][j] = min(right, down);
			}
		}
		return res[row - 1][col - 1];
	}
};

int main()
{
	return 0;
}