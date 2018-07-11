#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize)
{
	int numsCount = numsRowSize*numsColSize;
	int reshapeCount = r*c;
	if ( numsCount != reshapeCount )
	{
		(*returnSize) = numsRowSize;
		(*columnSizes) = (int*)malloc(numsRowSize*sizeof(int));
		for ( int i = 0; i < numsRowSize; i++ )
			(*columnSizes)[i] = numsColSize;
		return nums;
	}
	int** reshapeNum = (int**)malloc(r*sizeof(int*));
	(*returnSize) = r;
	(*columnSizes) = (int*)malloc(r*sizeof(int));
	for ( int i = 0; i < r; i++ )
		(*columnSizes)[i] = c;
	for ( int i = 0; i < r; i++ )
		reshapeNum[i] = (int*)malloc(c*sizeof(int));
	int m = 0, n = 0;
	for ( int i = 0; i < r; i++ )
	{
		for ( int j = 0; j < c; j++ )
		{
			reshapeNum[i][j] = nums[m][n];
			if ( n == numsColSize - 1 )
			{
				m++;
				n = 0;
			}
			else
				n++;
		}
	}
	return reshapeNum;
}

int main()
{
	return 0;
}