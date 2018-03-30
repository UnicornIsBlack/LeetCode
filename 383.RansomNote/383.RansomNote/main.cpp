#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* hashChar(char* str)
{
	int* hash = (int*)malloc(26 * sizeof(int));
	for ( int i = 0; i < 26; i++ )
	{
		hash[i] = 0;
	}
	int sLen = strlen(str);
	for ( int i = 0; i < sLen; i++ )
	{
		int index = str[i] - 'a';
		hash[index]++;
	}
	return hash;
}

bool canConstruct(char* ransomNote, char* magazine)
{
	int* ransomHash = hashChar(ransomNote);
	int* magazineHash = hashChar(magazine);
	bool flag = true;
	for ( int i = 0; i < 26; i++ )
	{
		if ( ransomHash[i] > magazineHash[i] )
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	return 0;
}