#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t reverseBits1(uint32_t n)
{
	int binary[32] = { 0 };
	uint32_t nClone = n;
	int i = 0;
	while ( nClone != 0 )
	{
		binary[i] = nClone % 2;
		i++;
		nClone /= 2;
	}
	uint32_t r = 0;
	for ( i = 0; i < 32; i++ )
	{
		r = r * 2 + binary[i];
	}
	return r;
}
uint32_t reverseBits(uint32_t n)
{
	int binary = 0;
	uint32_t r = 0;
	uint32_t nClone = n;
	for ( int i = 0; i < 32; i++ )
	{
		binary = nClone % 2;
		r = r * 2 + binary;
		nClone /= 2;
	}
	return r;
}

int main()
{
	uint32_t n = 43261596;
	uint32_t r = reverseBits(n);
	printf("%d\n", r);
	return 0;
}