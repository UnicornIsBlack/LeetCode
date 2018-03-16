#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAnagram(char* s, char* t)
{
	int charact_s[26] = { 0 };
	int charact_t[26] = { 0 };

	int sLen = strlen(s);
	int tLen = strlen(t);

	if ( sLen != tLen )
		return false;

	for ( int i = 0; i < sLen; i++ )
	{
		charact_s[s[i] - 'a']++;
		charact_t[t[i] - 'a']++;
	}
	for ( int i = 0; i < 26; i++ )
	{
		if ( charact_s[i] != charact_t[i] )
			return false;
	}
	return true;
}

int main()
{
	return 0;
}