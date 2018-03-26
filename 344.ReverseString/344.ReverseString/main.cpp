#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s)
{
	int sLen = strlen(s);
	if ( sLen <= 1 )
		return s;
	char* rStr = (char*)malloc((sLen + 1)*sizeof(char));
	int j = 0;
	for ( int i = 0; i < sLen; i++ )
	{
		j = sLen - 1 - i;
		rStr[i] = s[j];
	}
	rStr[sLen] = '\0';
	return rStr;
}

int main()
{
	return 0;
}