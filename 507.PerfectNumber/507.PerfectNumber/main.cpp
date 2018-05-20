#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


bool checkPerfectNumber(int num)
{
	if ( num == 0 )
		return false;
	int sum = 0;
	int mid = num / 2;
	bool flag = false;
	for ( int i = 1; i <= mid; i++ )
	{
		if ( num % i == 0 )
			sum += i;
	}
	if ( sum == num )
		flag = true;
	return flag;
}


int main()
{
	return 0;
}