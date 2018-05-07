#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int max = 0;
	int count = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] == 0 )
		{
			if ( max < count )
				max = count;
			count = 0;
		}
		else if ( nums[i] == 1 )
			count++;
	}
	if ( max < count )
		max = count;
	return max;
}

int main()
{
	return 0;
}