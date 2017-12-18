#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mySqrt(int x)
{
	if ( x <= 1 )
		return x;
	int start = 0;
	int end = x;
	while ( start <= end )
	{
		int mid = (start + end) / 2;
		int sq = x/mid;
		if ( sq == mid )
		{
			return mid;
		}
		else if ( sq < mid )
		{
			end = mid - 1;
		}
		else if ( sq > mid )
		{
			start = mid + 1;
		}
	}
	return end;
}

int main()
{
	int sqrt1 = mySqrt(0);
	printf("%d\n", sqrt1);
	return 0;
}