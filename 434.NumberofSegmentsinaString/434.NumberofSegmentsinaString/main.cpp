#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSegments(char* s)
{
	int count = 0;
	int sLen = strlen(s);
	bool flag = true;
	for ( int i = 0; i < sLen; i++ )
	{
		if ( s[i] != ' ' && flag )
		{
			flag = false;
			count++;
		}
		if ( s[i] == ' ' )
			flag = true;
	}
	return count;
}

int main()
{
	return 0;
}