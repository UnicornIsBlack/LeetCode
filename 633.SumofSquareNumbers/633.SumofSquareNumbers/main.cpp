#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


bool judgeSquareSum(int c)
{
	bool result = false;
	int s = sqrt((double)c);
	if ( s * s == c )
		return true;
	for ( int i = 1; i <= s; i++ )
	{
		int sub = c - i*i;
		int a = sqrt((double)sub);
		if ( a*a == sub )
		{
			result = true;
			break;
		}
	}
	return result;
}

int main()
{
	bool result = judgeSquareSum(5);
	printf("%d\n", result);
	return 0;;
}