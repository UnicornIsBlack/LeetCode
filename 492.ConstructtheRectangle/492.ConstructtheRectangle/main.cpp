#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* constructRectangle(int area, int* returnSize)
{
	int* rArray = (int*)malloc(2 * sizeof(int));
	int w = sqrt((double)area);
	int l = 0;
	while ( w >= 1 )
	{
		if ( area % w == 0 )
			break;
		w--;
	}
	l = area / w;
	(*returnSize) = 2;
	rArray[0] = l;
	rArray[1] = w;
	return rArray;
}

int main()
{
	return 0;
}