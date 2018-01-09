#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* getRow(int rowIndex, int* returnSize)
{
	int* retArray = (int*)malloc(sizeof(int)*(rowIndex + 1));
	(*returnSize) = rowIndex + 1;
	for ( int i = 0; i < rowIndex + 1; i++ )
	{
		for ( int j = i; j >=0 ; j-- )
		{
			if ( j == 0 || j == i )
			{
				retArray[j] = 1;
			}
			else
			{
				retArray[j] = retArray[j] + retArray[j - 1];
			}
		}
	}
	return retArray;
}

int main()
{
	int reSize = 0;
	int* arr = getRow(3, &reSize);
	for ( int i = 0; i < reSize; i++ )
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}