#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


int hammingWeight1(uint32_t n)
{
	int num = 0;
	uint32_t nClone = n;
	while ( nClone != 0 )
	{
		if ( nClone % 2 == 1 )
		{
			num++;
		}
		nClone /= 2;
	}
	return num;
}
int hammingWeight(uint32_t n)
{
	int num = 0;
	uint32_t nClone = n;
	while ( nClone != 0 )
	{
		num += ( nClone & 1 );
		nClone = nClone >> 1;
	}
	return num;
}
int main()
{
	uint32_t n = 11;
	int num = hammingWeight(n);
	printf("%d\n", num);
	return 0;
}