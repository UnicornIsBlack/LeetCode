#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseStrByIndex(char* s, int begin, int end)
{
	char tmp;
	while ( begin <= end )
	{
		tmp = s[begin];
		s[begin] = s[end];
		s[end] = tmp;
		begin++;
		end--;

	}
}

char* reverseStr(char* s, int k)
{
	int sLen = strlen(s);
	for ( int i = 0; i < sLen; i += (2 * k) )
	{
		if ( sLen - i >= k )
		{
			reverseStrByIndex(s, i, i + k - 1);
		}
		else
		{
			reverseStrByIndex(s, i, sLen - 1);
		}
	}
	return s;
}

int main()
{
	return 0;
}