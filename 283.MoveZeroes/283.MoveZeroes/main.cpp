#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveZeroes(int* nums, int numsSize)
{
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] != 0 )
			continue;
		int key = i;
		for ( int j = i + 1; j < numsSize; j++ )
		{
			if ( nums[j] == 0 )
				continue;
			nums[key] = nums[j];
			key = j;
		}
		nums[key] = 0;
	}
}

int main()
{
	int nums[] = { 0, 1, 0, 3, 12 };
	int numsSize = 5;
	moveZeroes(nums, numsSize);
	for ( int i = 0; i < numsSize; i++ )
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}