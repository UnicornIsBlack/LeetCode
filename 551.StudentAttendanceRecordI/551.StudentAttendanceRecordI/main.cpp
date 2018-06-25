#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bool checkRecord(char* s)
{
	int ACount = 0;
	int LCount = 0;
	bool LFlag = false;
	bool flag = true;
	int sLen = strlen(s);
	for ( int i = 0; i < sLen; i++ )
	{
		if ( s[i] == 'L' )
		{
			LCount++;
			if ( LCount >= 3 )
			{
				flag = false;
				break;
			}
		}
		else
		{
			LCount = 0;
			if ( s[i] == 'A' )
			{
				ACount++;
				if ( ACount >= 2 )
				{
					flag = false;
					break;
				}
			}
		}
	}
	return flag;
}

int main()
{
	return 0;
}