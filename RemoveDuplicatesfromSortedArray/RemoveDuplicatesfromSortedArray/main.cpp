#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize)
{
	int n = 0;
	int j = 0;
	if ( numsSize > 0 )
	{
		n++;
	}
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] != nums[j] )
		{
			n++;
			nums[n - 1] = nums[i];
			j = i;
		}
	}

	return n;
}

int main()
{
	int nums[] = { 1, 1, 2, 2, 4, 5, 5, 5, 6, 6 };
	int n = removeDuplicates(nums, 10);

	printf("%d\n", n);
	for ( int i = 0; i < n; i++ )
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}