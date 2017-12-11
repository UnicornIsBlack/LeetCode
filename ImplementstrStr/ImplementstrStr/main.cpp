#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
	int hLen = strlen(haystack);
	int nLen = strlen(needle);
	bool flag = true;
	for ( int i = 0; i <= hLen - nLen; i++ )
	{
		for ( int k = 0,j = i; k < nLen; k++,j++ )
		{
			if ( haystack[j] != needle[k] )
			{
				flag = false;
				break;
			}
		}
		if ( flag )
		{
			return i;
		}
		else
		{
			flag = true;
		}
	}
	return -1;
}

int main()
{

	char haystack[] = "helqlo";
	char needle[] = "ll";

	int n = strStr(haystack, needle);

	printf("%d\n", n);
	return 0;
}