#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	*returnSize = digitsSize;
	for ( int i = digitsSize - 1; i >= 0; i-- )
	{
		if ( digits[i] == 9 )
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			return digits;
		}
	}

	*returnSize = digitsSize + 1;
	int* returnDigits = (int*)malloc((*returnSize)*sizeof(int));
	returnDigits[0] = 1;
	for ( int i = 0; i < digitsSize; i++ )
	{
		returnDigits[i + 1] = digits[i];
	}
	return returnDigits;
}

int main()
{
	int digits[] = {0};
	int digitsSize = 1;
	int* returnDigits;
	int returnSize = 0;
	returnDigits = plusOne(digits, digitsSize, &returnSize);
	printf("%d\n", returnSize);
	for ( int i = 0; i < returnSize; i++ )
	{
		printf("%d", returnDigits[i]);
	}
	printf("\n");
	return 0;
}