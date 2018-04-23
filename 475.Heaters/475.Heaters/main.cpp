#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_quick(int* nums, int low, int high)
{
	if ( low > high )
		return;
	int key = nums[low];
	int tmp = 0;
	int i = low, j = high;
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
	sort_quick(nums, low, i - 1);
	sort_quick(nums, i + 1, high);
}
bool isWhole(int* houses, int housesSize, int* heaters, int heatersSize, int radius)
{
	bool flag = true;
	int* cover = (int*)malloc((housesSize)*sizeof(int));
	for ( int i = 0; i < housesSize; i++ )
	{
		cover[i] = 0;
	}
	for ( int i = 0; i < heatersSize; i++ )
	{
		int startIndex = heaters[i] - radius;
		int endIndex = heaters[i] + radius;
		if ( startIndex <= 0 )
			startIndex = houses[0];
		if ( endIndex > houses[housesSize - 1] )
			endIndex = houses[housesSize - 1];
		//printf("%d %d\n",startIndex,endIndex);
		for ( int j = 0; j < housesSize; j++ )
		{
			if ( houses[j] >= startIndex && houses[j] <= endIndex )
			{
				cover[j] = 1;
			}
		}
	}
	for ( int i = 0; i < housesSize; i++ )
	{
		if ( cover[i] == 0 )
		{
			flag = false;
			break;
		}
	}
	free(cover);
	return flag;
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
{
	int maxRadius = 0;
	int minRadius = 999999999;
	sort_quick(houses, 0, housesSize - 1);
	for ( int i = 0; i < heatersSize; i++ )
	{
		int aRadius = houses[housesSize - 1] - heaters[i];
		int bRadius = heaters[i] - houses[0];
		int min = 0;
		int max = 0;
		if ( aRadius > bRadius )
		{
			max = aRadius;
			min = bRadius;
		}
		else
		{
			max = bRadius;
			min = aRadius;
		}
		maxRadius = maxRadius > max ? maxRadius : max;
		minRadius = minRadius < min ? minRadius : min;
	}
	printf("%d\n", maxRadius);
	int i = minRadius;
	while ( i <= maxRadius )
	{
		if ( isWhole(houses, housesSize, heaters, heatersSize, i) )
			break;
		i++;
	}
	return i;
}

int main()
{
	return 0;
}