#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int climbStairs(int n)
{
	int stepOne = 1;
	int stepTwo = 1;
	int stepReturn = 1;
	for ( int i = 2; i <= n; i++ )
	{
		stepReturn = stepOne + stepTwo;
		stepOne = stepTwo;
		stepTwo = stepReturn;
	}
	return stepReturn;
}

int main()
{
	int num = climbStairs(44);
	printf("%d\n", num);
	return 0;
}