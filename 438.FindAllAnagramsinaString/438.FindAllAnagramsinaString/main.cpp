#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* hashStr(char* s, int start, int stop)
{
	int* hash = (int*)malloc(26 * sizeof(int));
	for ( int i = 0; i < 26; i++ )
	{
		hash[i] = 0;
	}
	for ( int i = start; i < stop; i++ )
	{
		int index = s[i] - 'a';
		hash[index]++;
	}
	return hash;
}
bool isSame(int* sHash, int* pHash)
{
	bool flag = true;
	for ( int i = 0; i < 26; i++ )
	{
		if ( sHash[i] != pHash[i] )
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int* findAnagrams(char* s, char* p, int* returnSize)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int upLimt = sLen - pLen;
	*returnSize = 0;
	int* pHash = hashStr(p, 0, pLen);
	int* anagram = (int*)malloc((upLimt + 1)*sizeof(int));
	int j = 0;
	for ( int i = 0; i <= upLimt; i++ )
	{
		int* sHash = hashStr(s, i, i + pLen);
		if ( isSame(sHash, pHash) )
		{
			(*returnSize)++;
			anagram[j] = i;
			j++;
		}
	}
	return anagram;
}

int main()
{
	return 0;
}