#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWord(char* s, int begin, int end)
{
	char tmp;
	while ( begin <= end )
	{
		tmp = s[begin];
		s[begin] = s[end];
		s[end] = tmp;
		begin++;
		end--;
	}
}

char* reverseWords(char* s)
{
	int sLen = strlen(s);
	int begin = -1;
	int end = -1;
	bool word = false;

	for ( int i = 0; i < sLen; i++ )
	{
		if ( !word && s[i] != ' ' )
		{
			begin = i;
			word = true;
		}
		if ( word && (i + 1 == sLen || s[i + 1] == ' ') )
		{
			end = i;
			word = false;
			reverseWord(s, begin, end);
		}
	}
	return s;
}


int main()
{
	return 0;
}