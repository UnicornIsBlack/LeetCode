#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int majorityElement(int* nums, int numsSize)
{
	int count = 0;
	int element = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( count == 0 || element == nums[i] )
		{
			count++;
			element = nums[i];
		}
		else
			count--;

	}
	return element;
}

int main()
{
	return 0;
}