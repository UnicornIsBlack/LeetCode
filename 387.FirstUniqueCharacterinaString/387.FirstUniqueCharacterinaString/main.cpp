#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* hashStr(char* s)
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

int firstUniqChar(char* s)
{
	int* hash = hashStr(s);
	int sLen = strlen(s);
	int flag = -1;
	for ( int i = 0; i < sLen; i++ )
	{
		int index = s[i] - 'a';
		if ( hash[index] == 1 )
		{
			flag = i;
			break;
		}
	}
	return flag;
}

int main()
{
	return 0;
}