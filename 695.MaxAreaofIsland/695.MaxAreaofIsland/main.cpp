#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution
{
	public:
	int maxAreaOfIsland(vector<vector<int>>& grid)
	{
		if ( grid.size() == 0 )
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		int maxArea = 0;
		for ( int i = 0; i < row; i++ )
		{
			for ( int j = 0; j < col; j++ )
			{
				if ( grid[i][j] )
					maxArea = max(maxArea, areaOfIsland(grid, i, j));
			}
		}
		return maxArea;
	}
	
	int areaOfIsland(vector<vector<int>> &grid,int i,int j)
	{
		if ( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() )
			return 0;
		if ( grid[i][j] )
		{
			grid[i][j] = 0;
			return 1 + areaOfIsland(grid, i, j - 1)
				+ areaOfIsland(grid, i + 1, j) 
				+ areaOfIsland(grid, i, j + 1) 
				+ areaOfIsland(grid, i - 1, j);
		}
		return 0;
	}
};

int main()
{
	return 0;
}