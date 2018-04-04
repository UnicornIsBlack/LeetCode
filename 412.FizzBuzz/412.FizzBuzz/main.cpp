#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char* intToStr(int n)
{
	int count = 1;
	int val = n;
	while ( val > 0 )
	{
		val /= 10;
		count++;
	}
	char* str = (char*)malloc(count*sizeof(char));
	count--;
	str[count] = '\0';
	val = n;
	while ( val > 0 )
	{
		count--;
		int mod = val % 10;
		val /= 10;
		str[count] = '0' + mod;
	}
	return str;

}
char* fizzBuzzByNum(int n)
{
	char* fizz;
	if ( n % 3 == 0 && n % 5 != 0 )
	{
		fizz = (char*)malloc(5 * sizeof(char));
		fizz[0] = 'F'; fizz[1] = 'i'; fizz[2] = 'z'; fizz[3] = 'z'; fizz[4] = '\0';
		return fizz;
	}
	else if ( n % 3 != 0 && n % 5 == 0 )
	{
		fizz = (char*)malloc(5 * sizeof(char));
		fizz[0] = 'B'; fizz[1] = 'u'; fizz[2] = 'z'; fizz[3] = 'z'; fizz[4] = '\0';
		return fizz;
	}
	else if ( n % 3 == 0 && n % 5 == 0 )
	{
		fizz = (char*)malloc(9 * sizeof(char));
		fizz[0] = 'F'; fizz[1] = 'i'; fizz[2] = 'z'; fizz[3] = 'z';
		fizz[4] = 'B'; fizz[5] = 'u'; fizz[6] = 'z'; fizz[7] = 'z'; fizz[8] = '\0';
		return fizz;
	}
	fizz = intToStr(n);
	return fizz;

}
char** fizzBuzz(int n, int* returnSize)
{
	char** fizz = (char**)malloc(n*sizeof(char*));
	(*returnSize) = n;
	for ( int i = 0; i < n; i++ )
	{
		fizz[i] = fizzBuzzByNum(i + 1);

	}
}

int main()
{
	return 0;
}