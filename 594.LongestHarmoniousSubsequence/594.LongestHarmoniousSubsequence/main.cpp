#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortFast(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int i = low, j = high;
	int key = nums[low];
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
int maxNum(int a, int b)
{
	return a > b ? a : b;
}
int findLHS(int* nums, int numsSize)
{
	int max = 0;
	int count = 0;
	int key = nums[0];
	sortFast(nums, 0, numsSize - 1);
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] - key == 0 || nums[i] - key == 1 )
			count++;
		else
		{
			if ( nums[i - 1] - key == 1 )
			{
				max = maxNum(max, count);
			}
			key = nums[i];
			count = 1;
		}
		if ( i == numsSize - 1 && nums[i] - key == 1)
			max = maxNum(max, count);
	}
	return max;
}

int main()
{
	return 0;
}