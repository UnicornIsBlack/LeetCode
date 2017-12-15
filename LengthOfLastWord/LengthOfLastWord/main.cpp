#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
	int sLen = strlen(s);
	bool flag = false;
	int lastLen = 0;
	for ( int i = sLen - 1; i >= 0; i-- )
	{
		if ( s[i] != ' ' )
		{
			lastLen++;
			flag = true;
		}

		if ( s[i] == ' ' && flag )
		{
			break;
		}
	}
	return lastLen;
}

int lengthOfLastWord1(char* s)
{
	int lastLen = 0;
	int sLen = strlen(s);
	int wLen = 0;
	for ( int i = 0; i < sLen; i++ )
	{
		if ( s[i] != ' ' )
		{
			wLen++;
		}
		else
		{
			if ( wLen > 0 )
			{
				lastLen = wLen;
			}
			wLen = 0;
		}
	}
	if ( s[sLen - 1] != ' ' )
	{
		lastLen = wLen;
	}
	return lastLen;
}

int main()
{
	char* s = "Todayisanicedy";
	int len = lengthOfLastWord(s);
	printf("%d\n", len);
	return 0;
}