#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sortQuick(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int i = low;
	int j = high;
	int key = nums[low];
	int tmp = 0;

	while ( i < j )
	{
		while ( i < j && nums[j] >= key )
			j--;
		while ( i < j && nums[i] <= key )
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
int minNum(int a, int b)
{
	return a < b ? a : b;
}
int distributeCandies(int* candies, int candiesSize)
{
	sortQuick(candies, 0, candiesSize - 1);
	int kind = 0;
	for ( int i = 0; i < candiesSize; i++ )
		kind += i == 0 || candies[i] != candies[i - 1];
	return minNum(kind, candiesSize / 2);
}

int main()
{
	return 0;
}