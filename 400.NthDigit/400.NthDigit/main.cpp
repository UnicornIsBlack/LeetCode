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
	int s = n / bit;
	int m = n % bit;
	if ( m > 0 )
		s++;
	else
		m = bit;
	num += (s - 1);
	m = bit - m;
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
	int nReturn = 0;
	while ( true )
	{
		if ( n <= num )
		{
			nReturn = returnInt(n, bit);
			break;
		}
		n -= num;
		num *= 10;
		num += 9;
		bit++;
	}
	return nReturn;
}

int main()
{
	return 0;
}