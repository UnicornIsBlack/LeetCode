#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPowerOfTwo(int n)
{
	return n > 0 && (n & (n - 1) == 0);
}


int main()
{
	return 0;
}