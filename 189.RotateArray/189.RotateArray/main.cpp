#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int* nums, int numsSize, int k)
{
	int j = 0;
	int tmp = 0;
	int s = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		j = j + k;
		j = j % numsSize;
		if ( j == s )
		{
			s++;
			j = s;
			continue;
		}
		tmp = nums[j];
		nums[j] = nums[s];
		nums[s] = tmp;
	}
}

int main()
{
	int nums[] = { 1, 2 ,3,4,5,6};
	int numsSize = 6;
	int k = 3;
	rotate(nums, numsSize, k);
	for ( int i = 0; i < numsSize; i++ )
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}