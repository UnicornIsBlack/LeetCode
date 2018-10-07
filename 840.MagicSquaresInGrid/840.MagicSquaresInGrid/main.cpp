#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numMagicSquaresInside(vector<vector<int>>& grid)
	{
		int count = 0;

		int rLen = grid.size();
		int cLen = grid[0].size();

		for ( int i = 0; i < rLen - 2; i++ )
		{
			for ( int j = 0; j < cLen - 2; j++ )
			{
				if ( isLegal(i, j, grid) )
					count++;
			}
		}

		return count;
	}
	bool isLegal(int i, int j, vector<vector<int>>& grid)
	{
		for ( int m = i; m < i + 3; m++ )
		{
			for ( int n = j; n < j + 3; n++ )
			{
				if ( grid[m][n] < 1 || grid[m][n] > 9 )
				{
					return false;
				}
			}
		}
		int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
		if ( grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != sum ||
			grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != sum ||
			grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != sum ||
			grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != sum ||
			grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != sum ||
			grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum ||
			grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum )
			return false;
		return true;
	}
};

int main()
{
	return 0;
}