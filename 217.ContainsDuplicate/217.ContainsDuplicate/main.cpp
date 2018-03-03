#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sortQuick(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int key = nums[low];
	int i = low, j = high;
	int tmp = 0;
	while ( i != j )
	{
		while ( nums[j] >= key && i < j )
			j--;
		while ( nums[i] <= key && i < j )
			i++;

		if ( i < j )
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}			
	}
	nums[low] = nums[i];
	nums[i] = key;
	sortQuick(nums, low, i - 1);
	sortQuick(nums, i + 1, high);

}

bool containsDuplicate(int* nums, int numsSize)
{
	if ( numsSize <= 1 )
		return false;
	sortQuick(nums, 0, numsSize - 1);
	int left = nums[0];
	int right = nums[1];
	for ( int i = 1; i < numsSize; i++ )
	{
		right = nums[i];
		left = nums[i - 1];
		if ( right == left )
			return true;
	}
	return false;
}

int main()
{
	int nums[] = { 1,2,33,10,5,6,9,8,9 };
	int numsSize = 9;
	bool flag = containsDuplicate(nums, numsSize);
	printf("%d\n", flag);
	return 0;
}