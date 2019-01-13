#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numIslands(vector<vector<char>>& grid)
	{
		int count = 0;
		if ( grid.size() == 0 || grid[0].size() == 0 )
			return count;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> map(row, vector<int>(col, 0));
		for ( int i = 0; i < row; i++ )
		{
			for ( int j = 0; j < col; j++ )
			{
				if ( grid[i][j] == '1' )
				{
					if ( map[i][j] == 1 )
						continue;
					isLands(grid, map, i, j);
					count++;
				}
			}
		}
		return count;
	}

	void isLands(vector<vector<char>>& grid, vector<vector<int>>& map, int i, int j)
	{
		if ( map[i][j] == 1 || grid[i][j] == '0' )
			return;
		map[i][j] = 1;
		if ( j > 0 )
			isLands(grid, map, i, j - 1);
		if ( i < grid.size() - 1 )
			isLands(grid, map, i + 1, j);
		if ( j < grid[0].size() - 1 )
			isLands(grid, map, i, j + 1);
		if ( i > 0 )
			isLands(grid, map, i - 1, j);
	}
};

int main()
{
	return 0;
}