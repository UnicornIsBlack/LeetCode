#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int* missNum;
	int* countNum = (int*)malloc(numsSize*sizeof(int));
	for ( int i = 0; i < numsSize; i++ )
	{
		countNum[i] = 0;
	}
	for ( int i = 0; i < numsSize; i++ )
	{
		countNum[nums[i] - 1]++;
		if ( countNum[nums[i] - 1] == 2 )
			(*returnSize)++;
	}
	missNum = (int*)malloc((*returnSize)*sizeof(int));
	for ( int i = 0,j = 0; i < numsSize; i++ )
	{
		if ( countNum[i] == 0 )
		{
			missNum[j] = i + 1;
			j++;
		}
	}
	return missNum;
}

int main()
{
	return 0;
}