#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution
{
	public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int row = obstacleGrid.size();
		if ( row == 0 )
			return 0;
		int col = obstacleGrid[0].size();
		vector<vector<int>> res(row, vector<int>(col, 0));
		res[0][0] = !obstacleGrid[0][0];
		for ( int i = 1; i < row; i++ )
		{
			if ( obstacleGrid[i][0] == 1 )
				res[i][0] = 0;
			else
				res[i][0] = res[i - 1][0];
		}
		for ( int i = 1; i < col; i++ )
		{
			if ( obstacleGrid[0][i] == 1 )
				res[0][i] = 0;
			else
				res[0][i] = res[0][i - 1];
		}
		for ( int i = 1; i < row; i++ )
		{
			for ( int j = 1; j < col; j++ )
			{
				if ( obstacleGrid[i][j] != 1 )
					res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
		}
		return res[row - 1][col - 1];
	}
};

int main()
{
	return 0;
}