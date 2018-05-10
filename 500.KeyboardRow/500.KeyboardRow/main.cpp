#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

bool isInOneLine(char* word, int wordSize)
{
	if ( wordSize == 0 )
		return true;
	bool flag = true;
	int keyboard[] = { 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };
	int index = (word[0] - 'a') >= 0 ? (word[0] - 'a') : (word[0] - 'A');
	int num = keyboard[index];
	for ( int i = 1; i < wordSize; i++ )
	{
		index = (word[i] - 'a') >= 0 ? (word[i] - 'a') : (word[i] - 'A');
		if ( keyboard[index] != num )
		{
			flag = false;
			break;
		}
	}
	return flag;
}
char** findWords(char** words, int wordsSize, int* returnSize)
{
	char** find = (char**)malloc(wordsSize*sizeof(char*));
	int j = 0;
	for ( int i = 0; i < wordsSize; i++ )
	{
		if ( isInOneLine(words[i], strlen(words[i])) )
		{
			find[j] = words[i];
			j++;
		}
	}
	(*returnSize) = j;
	return find;
}

int main()
{
	printf("%d\n", 'P' - 'A');
	return 0;
}