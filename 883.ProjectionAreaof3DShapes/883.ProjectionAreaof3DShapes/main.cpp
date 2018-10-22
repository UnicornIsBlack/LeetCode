#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int projectionArea(vector<vector<int>>& grid)
	{
		int area = 0;
		area += (grid.size()*grid[0].size());

		for ( int i = 0; i < grid.size(); i++ )
		{
			int maxArea = 0;
			for ( int j = 0; j < grid[0].size(); j++ )
			{
				maxArea = max(maxArea, grid[i][j]);
				if ( grid[i][j] == 0 )
					area--;
			}
			area += maxArea;
		}
		for ( int j = 0; j < grid[0].size(); j++ )
		{
			int maxArea = 0;
			for ( int i = 0; i < grid.size(); i++ )
			{
				maxArea = max(maxArea, grid[i][j]);
			}
			area += maxArea;
		}
		return area;
	}
};

int main()
{
	return 0;
}