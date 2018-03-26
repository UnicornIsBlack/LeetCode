#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInVowels(char* vowels, char c)
{
	bool flag = false;
	for ( int i = 0; i < 10; i++ )
	{
		if ( c == vowels[i] )
		{
			flag = true;
			break;
		}
	}
	return flag;
}

char* reverseVowels(char* s)
{
	int sLen = strlen(s);
	if ( sLen <= 1 )
		return s;
	char vowels[10] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
	int i = 0, j = sLen - 1;
	char tmp;
	while ( i < j )
	{
		while ( i < j && !isInVowels(vowels, s[j]) )
			j--;
		while ( i < j && !isInVowels(vowels, s[i]) )
			i++;
		if ( i < j )
		{
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
			i++;
			j--;
		}
	}
	return s;
}

int main()
{
	return 0;
}