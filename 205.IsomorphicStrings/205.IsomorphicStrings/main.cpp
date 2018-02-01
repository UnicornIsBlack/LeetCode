#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isIsomorphic(char* s, char* t)
{
	int sLen = strlen(s);
	int tLen = strlen(t);
	if ( sLen != tLen )
		return false;

	char* replace = (char*)malloc(128 * sizeof(char));
	bool* replaced = (bool*)malloc(128 * sizeof(bool));
	for ( int i = 0; i < 128; i++ )
	{
		replace[i] = '\0';
		replaced[i] = false;
	}
	for ( int i = 0; i < sLen; i++ )
	{
		if ( replace[s[i]] == '\0' )
		{
			if ( replaced[t[i]] )
				return false;
			replace[s[i]] = t[i];
			replaced[t[i]] = true;
			continue;
		}
		if ( replace[s[i]] != t[i] )
			return false;
	}
	return true;
}

int main()
{
	char s[] = "ega";
	char t[] = "add";
	bool r = isIsomorphic(s, t);
	printf("%d\n", r);
	return 0;
}