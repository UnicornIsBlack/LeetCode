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

int missingNumber(int* nums, int numsSize)
{
	sort_quick(nums, 0, numsSize - 1);
	int i = 0;
	for ( i = 0; i < numsSize; i++ )
	{
		if ( nums[i] != i )
			return i;
	}
	return i;
}

int main()
{
	return 0;
}