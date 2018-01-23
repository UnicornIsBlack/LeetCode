#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isHappy(int n)
{
	int sum = 0;
	int mod = 0;
	int flag[1000] = { 0 };
	while ( 1 )
	{
		sum = 0;
		while ( n != 0 )
		{
			mod = n % 10;
			sum += (mod * mod);
			n /= 10;
		}
		if ( sum == 1 )
			return true;
		else if ( flag[sum]  )
		{
			return false;
		}
		flag[sum] = 1;
		n = sum;

	}
	
}
int main()
{
	int n = 19;
	bool flag = isHappy(n);
	printf("%d\n", flag);
	return 0;
}