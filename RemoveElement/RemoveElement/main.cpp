#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val)
{
	int j = numsSize - 1;
	int n = numsSize;
	for ( int i = numsSize - 1; i >= 0; i-- )
	{
		if ( nums[i] == val )
		{
			nums[i] = nums[j];
			j--;
			n--;
		}
	}

	return n;
}

int main()
{
	int nums[] = { 1, 1, 2, 2, 3, 2, 3, 2, 3, 4 };
	int n = removeElement(nums, 10, 2);
	printf("%d\n", n);
	for ( int i = 0; i < n; i++ )
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}