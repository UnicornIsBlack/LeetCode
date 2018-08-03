#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minNum(int a, int b)
{
	return a < b ? a : b;
}
int maxNum(int a, int b)
{
	return a>b ? a : b;
}
int findUnsortedSubarray(int* nums, int numsSize)
{
	int begin = -1;
	int end = -2;
	int max = nums[0];
	int min = nums[numsSize - 1];
	for ( int i = 0; i < numsSize; i++ )
	{
		max = maxNum(max, nums[i]);
		min = minNum(min, nums[numsSize - 1 - i]);
		if ( nums[i] < max )
			end = i;
		if ( nums[numsSize - 1 - i] > min )
			begin = numsSize - 1 - i;
	}
	return end - begin + 1;
}

int main()
{
	return 0;
}