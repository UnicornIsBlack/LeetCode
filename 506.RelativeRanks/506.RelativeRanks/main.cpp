#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int* nums,int* index, int low, int high)
{
	if ( low > high )
		return;

	int key = nums[low];
	int keyIndex = index[low];
	int i = low;
	int j = high;
	int tmp = 0;
	while ( i < j )
	{
		while ( i < j && nums[j] <= key )
			j--;
		while ( i < j && nums[i] >= key )
			i++;
		if ( i < j )
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;

			tmp = index[i];
			index[i] = index[j];
			index[j] = tmp;
		}
	}
	nums[low] = nums[i];
	nums[i] = key;

	index[low] = index[i];
	index[i] = keyIndex;

	quick_sort(nums,index, low, i - 1);
	quick_sort(nums,index, i + 1, high);
}


/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** findRelativeRanks(int* nums, int numsSize, int* returnSize)
{
	int* indexs = (int*)malloc(numsSize*sizeof(int));
	for ( int i = 0; i < numsSize; i++ )
	{
		indexs[i] = i;
	}
	int* clone = (int*)malloc(numsSize*sizeof(int));
	for ( int i = 0; i < numsSize; i++ )
	{
		clone[i] = nums[i];
	}
	quick_sort(clone,indexs, 0, numsSize - 1);
	char* rank3[] = { 
		"Gold Medal",
		"Silver Medal",
		"Bronze Medal" 
	};
	char** ranks = (char**)malloc(numsSize*sizeof(char*));
	(*returnSize) = numsSize;
	int key = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		int index = indexs[i];
		if ( i == 0 )
			ranks[index] = rank3[0];
		else if ( i == 1 )
			ranks[index] = rank3[1];
		else if ( i == 2 )
			ranks[index] = rank3[2];
		else
		{
			int count = 0;
			int clone = i + 1;
			while ( clone != 0 )
			{
				clone /= 10;
				count++;
			}
			ranks[index] = (char*)malloc((count + 1)*sizeof(char));
			ranks[index][count] = '\0';
			clone = i + 1;
			int mod = 0;
			while ( clone != 0 )
			{
				count--;
				mod = clone % 10;
				clone /= 10;
				ranks[index][count] = '0' + mod;
			}
		}
	}
	return ranks;
}

int main()
{
	return 0;
}