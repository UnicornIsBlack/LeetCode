#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexArray(int* arr, int arrSize)
{
	int index = arrSize - 1;
	for ( int i = arrSize - 1; i >= 0; i-- )
	{
		if ( arr[i] > 0 )
			index = i;
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
	int rowIndex = indexArray(countRow, m);
	int colIndex = indexArray(countCol, n);
	free(countRow);
	free(countCol);
	return rowIndex * colIndex;
}

int main()
{
	return 0;
}