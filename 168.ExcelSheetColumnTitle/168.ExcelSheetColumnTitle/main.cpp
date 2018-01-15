#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int n)
{
	char* out = (char*)malloc(11 * sizeof(char));
	out[10] = '\0';
	int i = 9;
	while ( n > 0 )
	{
		n--;
		out[i] = (n % 26) + 'A';
		n /= 26;
		i--;
	}
	return out + i + 1;
}

int main()
{
	int n = 26;
	char* out = convertToTitle(n);
	printf("%s\n", out);
	return 0;
}