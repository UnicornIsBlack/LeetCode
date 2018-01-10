#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToInt(char word)
{
	if ( word >= 'a' && word <= 'z' )
	{
		return word - 'a';
	}
	else if (word >= 'A' && word <= 'Z')
	{
		return word - 'A';
	}
	else if ( word >= '0' && word <= '9' )
	{
		return -2 - word + '0';
	}
	else
		return -1;
}

bool isPalindrome(char* s)
{
	int sLen = strlen(s);
	if ( sLen == 0 )
		return true;
	int low = 0;
	int high = sLen - 1;
	while ( low <= high )
	{
		char front = s[low];
		char behind = s[high];
		int intFront = charToInt(front);
		int intBehind = charToInt(behind);
		if ( intFront == -1 )
		{
			low++;
			continue;
		}
		else if ( intBehind == -1 )
		{
			high--;
			continue;
		}
		if ( intFront == intBehind )
		{
			low++;
			high--;
		}
		else
			return false;
	}
	return true;
	
}

int main()
{
	char s[] = "0P";
	bool palindrome = isPalindrome(s);
	printf("%d\n", palindrome);
	return 0;
}