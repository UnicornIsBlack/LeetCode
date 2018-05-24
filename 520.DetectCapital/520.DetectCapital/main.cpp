#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCapital(char s)
{
	bool flag = true;
	if ( s >= 'a' && s <= 'z' )
		flag = false;
	else if ( s >= 'A' && s <= 'Z' )
		flag = true;
	else
		return -1;
	return flag;
}
bool detectCapitalUse(char* word)
{
	int len = strlen(word);
	if ( len == 0 )
		return true;
	bool first = false;
	if ( isCapital(word[0]) == -1 )
		return false;
	else if (isCapital(word[0]))
		first = true;
	if ( len == 1 )
		return true;
	bool second = false;
	if ( isCapital(word[1]) == -1 )
		return false;
	else if ( isCapital(word[1]) )
		second = true;
	if ( !first&&second )
		return false;
	int last = 0;
	for ( int i = 2; i < len; i++ )
	{
		last = isCapital(word[i]);
		if ( last == -1 || last != second )
			return false;
	}
	return true;
}

int main()
{
	return 0;
}