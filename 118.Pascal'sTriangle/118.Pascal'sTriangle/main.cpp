#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* Return an array of arrays.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** generate(int numRows, int** columnSizes)
{
	(*columnSizes) = (int*)malloc(numRows*sizeof(int));
	int** returnArray = (int**)malloc(numRows*sizeof(int*));
	for ( int i = 1; i <= numRows; i++ )
	{
		returnArray[i - 1] = (int*)malloc(i*sizeof(int));
		(*columnSizes)[i - 1] = i;
		for ( int j = 0; j < i; j++ )
		{
			if ( j == 0 || j == i - 1 )
			{
				returnArray[i - 1][j] = 1;
			}
			else
			{
				returnArray[i - 1][j] = returnArray[i - 2][j] + returnArray[i - 2][j - 1];
			}
		}
	}
	return returnArray;
}

int main()
{
	int* columnSizes = { 0 };
	int** arr = generate(5, &columnSizes);
	for ( int i = 0; i < 5; i++ )
	{
		for ( int j = 0; j < columnSizes[i]; j++ )
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}