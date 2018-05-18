#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int* nums, int low, int high)
{
	if ( low > high )
		return;

	int key = nums[low];
	int i = low;
	int j = high;
	int tmp = 0;
	while ( i < j )
	{
		while ( i < j && nums[j] >= key )
			j--;
		while ( i < j && nums[i] <= key )
			i++;
		if ( i < j )
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	}
	nums[low] = nums[i];
	nums[i] = key;
	quick_sort(nums, low, i - 1);
	quick_sort(nums, i + 1, high);
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** findRelativeRanks(int* nums, int numsSize, int* returnSize)
{
	int* index = (int*)malloc(numsSize*sizeof(int));
	int* clone = (int*)malloc(numsSize*sizeof(int));
	for ( int i = 0; i < numsSize; i++ )
	{
		clone[i] = nums[i];
	}
	quick_sort(clone, 0, numsSize - 1);

	char* rank3[] = { 
		"Gold Medal",
		"Silver Medal",
		"Bronze Medal" };

	char** ranks = (char**)malloc(numsSize*sizeof(char*));
	(*returnSize) = numsSize;
	int key = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		key = clone[i];

	}
	return ranks;
}

int main()
{
	return 0;
}