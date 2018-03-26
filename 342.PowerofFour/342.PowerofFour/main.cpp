#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPowerOfFour(int num)
{
	if ( num <= 0 )
		return false;
	while ( num >= 4 )
	{
		if ( num % 4 != 0 )
			return false;
		else
			num = num / 4;
	}
	if ( num == 1 )
		return true;
	return false;
}

int main()
{
	return 0;
}