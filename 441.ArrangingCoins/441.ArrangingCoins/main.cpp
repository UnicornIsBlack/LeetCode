#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum(int n)
{
	if ( n % 2 == 0 )
		return (n / 2)*(n + 1);
	else
		return n*((n + 1) / 2);
}

int arrangeCoins(int n)
{
	double k = n;
	int i = sqrt(k)*1.414;
	printf("%d\n", i);
	while ( true )
	{
		int s = sum(i);
		if ( s < 0 )
			break;
		printf("%d\n", s);
		if ( s == n )
			return i;
		else if ( s > n )
			break;
		i++;
	}
	return i - 1;
}

int main()
{
	int n = 2147483647;
	arrangeCoins(n);
	return 0;
}