#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void quick_sort(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int key = nums[low];
	int tmp = 0;
	int i = low;
	int j = high;
	while ( i < j )
	{
		while ( nums[j] >= key && i < j )
			j--;
		while ( nums[i] <= key && i < j )
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

int findPairs(int* nums, int numsSize, int k)
{
	quick_sort(nums, 0, numsSize - 1);
	int count = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( i >= 1 && nums[i - 1] == nums[i] )
			continue;
		for ( int j = i + 1; j < numsSize; j++ )
		{
			if ( j > i + 1 && nums[j] == nums[j - 1] )
				continue;
			if ( nums[j] - nums[i] == k )
				count++;
			if ( nums[j] - nums[i] > k )
				break;
		}
	}
	return count;
}

int main()
{
	return 0;
}