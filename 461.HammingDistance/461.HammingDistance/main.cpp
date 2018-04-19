#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingDistance(int x, int y)
{
	int val = x ^ y;
	int count = 0;
	while ( val != 0 )
	{
		count += val & 1;
		val = val >> 1;
	}
	return count;
}

int main()
{
	return 0;
}