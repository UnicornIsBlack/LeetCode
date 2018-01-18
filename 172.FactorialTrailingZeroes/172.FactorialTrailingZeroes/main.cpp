#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trailingZeroes(int n)
{
	if ( n >= 5 )
	{
		return n / 5 + trailingZeroes(n / 5);
	}
	else
		return 0;
}

int main()
{
	return 0;
}