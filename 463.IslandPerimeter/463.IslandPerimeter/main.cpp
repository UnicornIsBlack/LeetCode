#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int onePerimeter(int** grid, int gridRowSize, int gridColSize, int i, int j)
{
	int perimeter = 4;
	if ( j != 0 )
		perimeter -= grid[i][j - 1];
	if ( j != gridColSize - 1 )
		perimeter -= grid[i][j + 1];
	if ( i != 0 )
		perimeter -= grid[i - 1][j];
	if ( i != gridRowSize - 1 )
		perimeter -= grid[i + 1][j];
	return perimeter;

}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
	int perimeter = 0;
	for ( int i = 0; i < gridRowSize; i++ )
	{
		for ( int j = 0; j < gridColSize; j++ )
		{
			if ( grid[i][j] == 0 )
				continue;
			perimeter += onePerimeter(grid, gridRowSize, gridColSize, i, j);
		}
	}
	return perimeter;
}

int main()
{
	return 0;
}