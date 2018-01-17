#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int titleToNumber(char* s)
{
	int num = 0;
	int sLen = strlen(s);
	for ( int i = 0; i < sLen; i++ )
	{
		int x = s[i] - 'A';
		x++;
		num = num * 26 + x;
	}
	return num;
}

int main()
{
	char* s = "AB";
	int n = titleToNumber(s);
	printf("%d\n", n);
	return 0;
}