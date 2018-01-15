#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	int i = 0;
	int j = numbersSize - 1;
	int sum = numbers[i] + numbers[j];
	while ( sum != target )
	{
		if ( sum > target )
			j--;
		else
			i++;
		sum = numbers[i] + numbers[j];
	}
	*returnSize = 2;
	int* reArr = (int*)malloc(2 * sizeof(int));
	reArr[0] = i + 1;
	reArr[1] = j + 1;
	return reArr;
}

int main()
{
	return 0;
}