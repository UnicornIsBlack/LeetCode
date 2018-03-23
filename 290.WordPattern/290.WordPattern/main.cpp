#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyStr(char* wordStr, char* str, int start, int len)
{
	for ( int i = 0; i < len; i++ )
	{
		wordStr[i] = str[i + start];
	}
}

char** resolveStr(char* str,int* len)
{
	char** wordStr;
	int spaceCount = 0;
	int sLen = strlen(str);
	for ( int i = 0; i < sLen; i++ )
	{
		if ( str[i] == ' ' )
			spaceCount++;
	}
	(*len) = spaceCount + 1;
	wordStr = (char**)malloc((spaceCount + 1)*sizeof(char*));
	int nLen = 0;
	int indexStart = 0;
	int wordIndex = 0;
	for ( int i = 0; i <= sLen; i++ )
	{
		if ( i == sLen )
		{
			nLen = i - indexStart + 1;
		}
		else if ( str[i] == ' ' )
		{
			nLen = i - indexStart;
		}
		else
			continue;
		wordStr[wordIndex] = (char*)malloc((nLen + 1)*sizeof(char));
		copyStr(wordStr[wordIndex], str, indexStart, nLen);
		wordStr[wordIndex][nLen] = '\0';
		wordIndex++;
		indexStart = i + 1;
	}
	return wordStr;
}

bool isSame(char* aStr, char* bStr)
{
	int aLen = strlen(aStr);
	int bLen = strlen(bStr);
	if ( aLen != bLen )
		return false;
	bool flag = true;
	for ( int i = 0; i < aLen; i++ )
	{
		if ( aStr[i] != bStr[i] )
		{
			flag = false;
			break;
		}
	}
	return flag;
}
bool wordPattern(char* pattern, char* str)
{
	bool flag = true;
	int wLen = 0;
	char** wordStr = resolveStr(str,&wLen);
	int len = strlen(pattern);
	if ( len != wLen )
		return false;
	bool isTrue = true;
	for ( int i = 0; i < len; i++ )
	{
		for ( int j = i + 1; j < len; j++ )
		{
			isTrue = isSame(wordStr[i], wordStr[j]);
			if ( pattern[i] == pattern[j] && !isTrue )
			{
				return false;
			}
			else if ( pattern[i] != pattern[j] && isTrue )
			{
				return false;
			}
		}
	}
	return flag;
}

int main()
{
	char* pattern = "abac";
	char* str = "cat dog cat dog";
	bool flag = wordPattern(pattern, str);
	printf("%d\n", flag);
	return 0;
}