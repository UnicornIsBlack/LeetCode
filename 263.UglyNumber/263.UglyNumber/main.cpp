#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isUgly(int num)
{
	if ( num <= 0 )
		return false;
	if ( num <= 3 )
		return true;

	while ( num % 2 == 0 || num % 3 == 0 || num % 5 == 0 )
	{
		if ( num % 2 == 0 )
			num /= 2;
		else if ( num % 3 == 0 )
			num /= 3;
		else if ( num % 5 == 0 )
			num /= 5;
	}
	if ( num == 1 )
		return true;
	return false;
}

int main()
{
	return 0;
}