#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int* nums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize)
{
	NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
	obj->nums = (int*)malloc(numsSize*sizeof(int));
	for ( int i = 0; i < numsSize; i++ )
	{
		obj->nums[i] = nums[i];
	}
	return obj;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
	int count = 0;
	for ( int k = i; k <= j; k++ )
	{
		count += obj->nums[k];
	}
	return count;
}

void numArrayFree(NumArray* obj)
{
	free(obj->nums);
	free(obj);
}

/**
* Your NumArray struct will be instantiated and called as such:
* struct NumArray* obj = numArrayCreate(nums, numsSize);
* int param_1 = numArraySumRange(obj, i, j);
* numArrayFree(obj);
*/

int main()
{
	return 0;
}