#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
Method one: Time limit
Method two: find the max num , and let it sub 1 , is same with others add 1
			find the min num , then let others sub 1 to min num , 
*/

//int indexNums(int* nums, int numsSize)
//{
//	int index = 0;
//	int max = 0;
//	for ( int i = 0; i < numsSize; i++ )
//	{
//		if ( nums[i] > max )
//		{
//			index = i;
//			max = nums[i];
//		}
//	}
//	return index;
//}
//
//bool isSame(int* nums, int numsSize)
//{
//	bool flag = true;
//	int val = nums[0];
//	for ( int i = 0; i < numsSize; i++ )
//	{
//		if ( nums[i] != val )
//		{
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//
//void moveOnce(int* nums, int numsSize, int index)
//{
//	for ( int i = 0; i < numsSize; i++ )
//	{
//		if ( i == index )
//			continue;
//		nums[i]++;
//	}
//}
//
//int minMoves(int* nums, int numsSize)
//{
//	int count = 0;
//	while ( !isSame(nums, numsSize) )
//	{
//		int index = indexNums(nums, numsSize);
//		moveOnce(nums, numsSize, index);
//		count++;
//	}
//	return count;
//}

int findMinNum(int* nums, int numsSize)
{
	int min = nums[0];
	for ( int i = 0; i < numsSize; i++ )
	{
		if ( nums[i] < min )
			min = nums[i];
	}
	return min;
}

int minMoves(int* nums, int numsSize)
{
	int min = findMinNum(nums, numsSize);
	int count = 0;
	for ( int i = 0; i < numsSize; i++ )
	{
		count += (nums[i] - min);
	}
	return count;
}

int main()
{
	return 0;
}