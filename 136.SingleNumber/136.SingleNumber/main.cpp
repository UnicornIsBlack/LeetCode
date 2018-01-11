#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int* nums, int numsSize)
{
	int num = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		num ^= nums[i];
	}
	return num;
}

int main()
{
	return 0;
}