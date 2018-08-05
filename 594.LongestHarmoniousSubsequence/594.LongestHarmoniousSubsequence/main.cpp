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
	int countSecond = 0;
	int key = nums[0];
	sortFast(nums, 0, numsSize - 1);
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] - key == 0 )
			count++;
		else if ( nums[i] - key == 1 )
		{
			count++;
			countSecond++;
		}
		else
		{
			if ( nums[i - 1] - key == 1 )
			{
				max = maxNum(max, count);
			}

			if ( nums[i] - nums[i - 1] == 1 )
			{
				count = countSecond + 1;
				countSecond = 1;
				key = nums[i - 1];
			}
			else
			{
				count = 1;
				countSecond = 0;
				key = nums[i];
			}
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