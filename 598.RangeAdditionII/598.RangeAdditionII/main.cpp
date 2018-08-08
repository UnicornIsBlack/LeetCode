#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexArray(int* arr, int arrSize)
{
	int max = arr[0];
	int index = 0;
	for ( int i = 0; i < arrSize; i++ )
	{
		if ( i != 0 && arr[i] >= max )
		{
			max = arr[i];
			index = i;
		}
		else if ( arr[i] < max )
			break;
	}
	return index+1;
}

int maxCount(int m, int n, int** ops, int opsRowSize, int opsColSize)
{
	int* countRow = (int*)malloc(m*sizeof(int));
	int* countCol = (int*)malloc(n*sizeof(int));
	for ( int i = 0; i < m; i++ )
	{
		countRow[i] = 0;
	}
	for ( int i = 0; i < n; i++ )
	{
		countCol[i] = 0;
	}
	for ( int i = 0; i < opsRowSize; i++ )
	{
		countRow[ops[i][0] - 1]++;
		countCol[ops[i][1] - 1]++;
	}
	int maxRow = indexArray(countRow, m);
	int maxCol = indexArray(countCol, n);
	 
}

int main()
{
	return 0;
}