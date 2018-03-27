#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_quick(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int key = nums[low];
	int tmp = 0;
	int i = low, j = high;
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
	sort_quick(nums, low, i - 1);
	sort_quick(nums, i + 1, high);
}

int isInNum(int* nums, int numsSize, int val, int index)
{
	if ( index >= numsSize )
		return -1;
	int valIndex = -1;
	for ( int i = index; i < numsSize; i++ )
	{
		if ( val == nums[i] )
		{
			valIndex = i;
			break;
		}
	}
	return valIndex;
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	sort_quick(nums1, 0, nums1Size - 1);
	sort_quick(nums2, 0, nums2Size - 1);
	int k = 0;
	int index = 0;
	int count = 0;
	int before = nums2[0];
	for ( int i = 0; i < nums2Size; i++ )
	{
		if ( i > 0 && nums2[i] == before )
		{
			continue;
		}
		index = isInNum(nums1, nums1Size, nums2[i], k);
		if ( index != -1 )
		{
			count++;
			k = index + 1;
		}
		before = nums2[i];
	}
	(*returnSize) = count;
	printf("%d\n", count);
	int* result = (int*)malloc(count*sizeof(int));
	int rIndex = 0;
	k = 0;
	for ( int i = 0; i < nums2Size; i++ )
	{
		if ( i > 0 && nums2[i] == before )
		{
			continue;
		}
		index = isInNum(nums1, nums1Size, nums2[i], k);
		if ( index != -1 )
		{
			count++;
			k = index + 1;
			result[rIndex] = nums2[i];
			rIndex++;
		}
		before = nums2[i];
	}
	return result;
}

int main()
{
	int nums1[] = { 1, 2, 2, 1 };
	int nums2[] = { 2, 2 };
	int nums1Size = 4;
	int nums2Size = 2;
	int* result = intersection(nums1, nums1Size, nums2, nums2Size);
	return 0;
}