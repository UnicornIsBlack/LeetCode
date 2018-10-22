#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int surfaceArea(vector<vector<int>>& grid)
	{
		int sum = 0;
		for ( int i = 0; i < grid.size(); i++ )
		{
			for ( int j = 0; j < grid[0].size(); j++ )
			{
				if ( grid[i][j] == 0 )
					continue;
				sum += (grid[i][j] * 6 - (grid[i][j] - 1) * 2);
				if ( i != grid.size() - 1 )
				{
					int minArea = min(grid[i][j], grid[i + 1][j]);
					sum -= (minArea * 2);
				}
				if ( j != grid[0].size() - 1 )
				{
					int minArea = min(grid[i][j], grid[i][j + 1]);
					sum -= (minArea * 2);
				}
			}
		}
		return sum;
	}
};

int main()
{
	return 0;
}