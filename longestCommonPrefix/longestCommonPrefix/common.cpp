#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 100

char* longestCommonPrefix(char** strs, int strsSize)
{
	if ( strsSize == 0 )
	{
		return "";
	}

	int comLen = 0;
	bool flag = false;
	char comChar;

	while ( true )
	{
		if ( comLen >= strlen(strs[0]) )
		{
			break;
		}
		comChar = strs[0][comLen];

		for ( int i = 0; i < strsSize; i++ )
		{
			if ( comLen + 1 > strlen(strs[i]) || comChar != strs[i][comLen] )
			{
				flag = true;
				break;
			}
		}

		if ( flag )
		{
			break;
		}
		comLen++;
	}
	char* comPrefix = (char*)malloc(sizeof(char)*(comLen+1));
	for ( int i = 0; i < comLen; i++ )
	{
		comPrefix[i] = strs[0][i];
	}
	comPrefix[comLen] = '\0';
	return comPrefix;
}


int main()
{
	char* strs[] = {
		"geeksforgeeks",
		"geeks",
		"geek",
		"geezer"
	};

	char* lonComPre;
	lonComPre = longestCommonPrefix(strs, 4);
	printf("%s\n", lonComPre);
	return 0;
}