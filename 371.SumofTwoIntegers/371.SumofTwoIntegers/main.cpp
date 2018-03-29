#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSum(int a, int b)
{
	int c = 0;
	while ( b != 0 )
	{
		c = a & b;
		a ^= b;
		b = c << 1;
	}
	return a;
}

int main()
{
	return 0;
}