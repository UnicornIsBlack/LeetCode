#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
**使用厄拉多塞筛法
*/

int countPrimes(int n)
{
	int count = 0;
	bool* flag = (bool*)malloc(n*sizeof(bool));
	for ( int i = 1; i < n; i++ )
	{
		flag[i] = true;
	}
	flag[1] = false;
	for ( int i = 2; i < n; i++ )
	{
		if ( !flag[i] )
			continue;
		count++;
		for ( int j = 2; j < n; j++ )
		{
			int mul = i*j;
			if ( mul > n )
				break;
			flag[mul] = false;
		}
	}
	return count;
}

int main()
{
	int n = 2;
	int count = countPrimes(n);
	printf("%d\n", count);
	return 0;
}