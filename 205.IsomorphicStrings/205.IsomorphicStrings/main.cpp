#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isIsomorphic(char* s, char* t)
{
	int sLen = strlen(s);
	int tLen = strlen(t);
	if ( sLen != tLen )
		return false;

	char* replace = (char*)malloc(26 * sizeof(char));
	bool* replaced = (bool*)malloc(26 * sizeof(bool));
	for ( int i = 0; i < 26; i++ )
	{
		replace[i] = '#';
		replaced[i] = false;
	}
	int sIndex;
	int tIndex;
	for ( int i = 0; i < sLen; i++ )
	{
		sIndex = s[i] - 'a';
		tIndex = t[i] - 'a';
		if ( replace[sIndex] == '#' )
		{
			if ( replaced[tIndex] )
				return false;
			replace[sIndex] = t[i];
			replaced[tIndex] = true;
			continue;
		}
		if ( replace[sIndex] != t[i] )
			return false;
	}
	return true;
}

int main()
{
	char s[] = "egga";
	char t[] = "add";
	bool r = isIsomorphic(s, t);
	printf("%d\n", r);
	return 0;
}