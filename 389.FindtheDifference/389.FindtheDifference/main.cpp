#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* hashStr(char*s)
{
	int* hash = (int*)malloc(26 * sizeof(int));
	for ( int i = 0; i < 26; i++ )
	{
		hash[i] = 0;
	}
	int sLen = strlen(s);
	for ( int i = 0; i < sLen; i++ )
	{
		int index = s[i] - 'a';
		hash[index]++;
	}
	return hash;
}

char findTheDifference(char* s, char* t)
{
	int* sHash = hashStr(s);
	int* tHash = hashStr(t);
	char c = ' ';
	for ( int i = 0; i < 26; i++ )
	{
		if ( sHash[i] != tHash[i] )
		{
			c = i + 'a';
			break;
		}
	}
	return c;
}

int main()
{
	return 0;
}