#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findComplement(int num)
{
	int count = 0;
	int mod = 0;
	int complement = 0;
	while ( num != 0 )
	{
		mod = num % 2;
		num /= 2;
		mod ^= 1;
		complement += (mod << count);
		count++;
	}
	return complement;
}

int main()
{
	return 0;
}