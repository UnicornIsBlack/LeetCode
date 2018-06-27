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
	int tmp;
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

int minNum(int a, int b)
{
	return a < b ? a : b;
}

int arrayPairSum(int* nums, int numsSize)
{
	quick_sort(nums, 0, numsSize - 1);
	int max = 0;
	for ( int i = 0; i < numsSize; i += 2 )
	{
		max += minNum(nums[i], nums[i + 1]);
	}
	return max;
}

int main()
{
	return 0;
}