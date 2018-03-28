#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPerfectSquare(int num)
{
	int m = 1;
	int up = num / 2 + 1;
	while ( m <= up )
	{
		if ( num == m * m )
			return true;
		m++;
	}
	return false;
}

int main()
{
	return 0;
}