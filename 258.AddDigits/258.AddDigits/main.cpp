#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addDigits(int num)
{
	int n = num;
	int quot = 0;
	int rem = 0;
	while ( n >= 10 )
	{
		quot = n;
		n = 0;
		while ( quot != 0 )
		{
			rem = quot % 10;
			quot /= 10;
			n += rem;
		}
	}
	return n;
}

int main()
{
	return 0;
}