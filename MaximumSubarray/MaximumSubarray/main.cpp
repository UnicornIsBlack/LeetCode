#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
二维数组分配内存空间要先分配行，再分配列
释放时要先释放列，再释放行

分配
int **arr = (int **)malloc(n*sizeof(int *));
for(i=0;i<n;i++)
	arr[i] = (int *)malloc(m*sizeof(int));

释放
for (i = 0; i < n; i++)
	free(arr[i]);
free(arr);
*/

int max(int x, int y)
{
	return x > y ? x : y;
}
int maxSubArray(int* nums, int numsSize)
{
	int curSub = -999999;
	int maxSub = -999999;

	if ( numsSize == 1 )
	{
		return nums[0];
	}

	for ( int i = 0; i < numsSize; i++ )
	{
		curSub = max(curSub + nums[i],nums[i]);
		maxSub = max(maxSub, curSub);
	}

	return maxSub;

}

int main()
{
	int nums[] = { 4,-1,1,2 };
	int max = maxSubArray(nums, 4);
	printf("%d\n", max);
	return 0;
}