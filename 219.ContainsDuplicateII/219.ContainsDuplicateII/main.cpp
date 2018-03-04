#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i = 0, j = 0;
	bool flag = false;

	for ( i = 0; i < numsSize; i++ )
	{
		for ( j = i + 1; j < numsSize; j++ )
		{
			if ( (nums[i] == nums[j]) && ( ( j - i ) <= k ) )
				flag = true;
		}
	}
	return flag;
}

int main()
{
	int nums[] = { 1,0,1,1 };
	int numsSize = 4;
	int k = 1;
	bool flag = containsNearbyDuplicate(nums, numsSize, k);
	printf("%d\n", flag);
	return 0;
}