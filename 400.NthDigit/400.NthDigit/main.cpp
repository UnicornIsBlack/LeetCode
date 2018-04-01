#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int returnInt(int n, int bit)
{
	int num = 1;
	int val = 0;
	for ( int i = 1; i < bit; i++ )
	{
		num *= 10;
	}
	printf("%d   \n", num);
	int s = n / bit;
	int m = n % bit;
	if ( m > 0 )
		s++;
	else
		m = bit;
	num += (s - 1);
	m = bit - m;
	printf("m=%d,num=%d\n", m, num);
	for ( int i = 0; i < bit; i++ )
	{
		val = num % 10;
		if ( i == m )
			break;
		num /= 10;
	}
	return val;
}

int findNthDigit(int n)
{
	int num = 9;
	int bit = 1; 
	int upLim = num * bit;
	int nReturn = 0;
	while ( true )
	{
		if ( n <= upLim || upLim <= 0 )
		{
			nReturn = returnInt(n, bit);
			break;
		}
		printf("%d,%d,%d\n", n, bit,upLim);
		n -= upLim;
		num *= 10;
		bit++;
		upLim = num * bit;
	}
	return nReturn;
}

int main()
{
	int val = findNthDigit(1000000000);
	printf("val=%d\n", val);
	return 0;
}