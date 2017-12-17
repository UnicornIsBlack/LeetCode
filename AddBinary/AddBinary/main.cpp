#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b)
{
	int aLen = strlen(a);
	int bLen = strlen(b);
	int cLen = 0;
	if ( aLen > bLen )
	{
		cLen = aLen + 2;
	}
	else
	{
		cLen = bLen + 2;
	}
	char* c = (char*)malloc(cLen*(sizeof(char)));
	c[cLen - 1] = '\0';
	c[cLen - 2] = '0';
	int aIndex = aLen - 1;
	int bIndex = bLen - 1;
	for ( int i = cLen - 2; i > 0; i-- )
	{
		int  sub = cLen - i - 1;
		int aInt = 0;
		int bInt = 0;
		int cInt = c[i] - '0';
		if ( sub > aLen )
		{
			bInt = b[bIndex] - '0';
			bIndex--;
		}
		else if ( sub > bLen )
		{
			aInt = a[aIndex] - '0';
			aIndex--;
		}
		else
		{
			aInt = a[aIndex] - '0';
			bInt = b[bIndex] - '0';
			aIndex--;
			bIndex--;
		}
		cInt = aInt + bInt + cInt;
		if ( cInt >= 2 )
		{
			c[i - 1] = '1';
			c[i] = '0' + (cInt - 2);
		}
		else
		{
			c[i - 1] = '0';
			c[i] = '0' + cInt;
		}
	}
	if ( c[0] == '0' )
		c++;
	return c;
}

int main()
{
	char a[] = "11";
	char b[] = "110";
	char* c = addBinary(a, b);
	printf("%s\n", c);
	return 0;
}