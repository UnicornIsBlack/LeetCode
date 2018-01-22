#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a, int b)
{
	return a > b ? a : b;
}
int rob(int* nums, int numsSize)
{
	if ( numsSize == 0 )
		return 0;
	if ( numsSize == 1 )
		return nums[0];
	if ( numsSize == 2 )
		return max(nums[0], nums[1]);
	int* sum = (int*)malloc((numsSize + 1)*sizeof(int));
	sum[0] = 0;
	sum[1] = nums[0];
	sum[2] = max(nums[0], nums[1]);

	for ( int i = 2; i < numsSize; i++ )
	{
		sum[i + 1] = max((sum[i - 1] + nums[i]), sum[i]);
	}
	return sum[numsSize];
}


int main()
{
	return 0;
}