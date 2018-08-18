#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortFast(int* nums, int low, int high)
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
	sortFast(nums, low, i - 1);
	sortFast(nums, i + 1, high);
}

int maximumProduct(int* nums, int numsSize)
{
	sortFast(nums, 0, numsSize - 1);
	int a = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
	int b = nums[0] * nums[1] * nums[numsSize - 1];
	return a > b ? a : b;
}

int main()
{
	return 0;
}