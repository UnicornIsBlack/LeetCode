#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int* nums, int numsSize, int target)
{
	int low = 0;
	int high = numsSize - 1;

	while ( low <= high )
	{
		int mid = (low + high) / 2;

		if ( nums[mid] == target )
		{
			return mid;
		}
		else if ( nums[mid] < target )
		{
			low = mid + 1;
		}
		else if ( nums[mid] > target )
		{
			high = mid - 1;
		}
	}
	return high + 1;
}

int main()
{

	int nums[] = { 1, 2, 6, 6, 7, 9, 13 };
	int numsSize = 7;
	int target = 5;
	int n = searchInsert(nums, numsSize, target);

	printf("%d\n", n);
	return 0;
}