#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToBase7(int num)
{
	if ( num == 0 )
		return "0";
	int flag = true;
	int count = 0;
	int clone = num;
	if ( num < 0 )
	{
		count = 1;
		flag = false;
		clone = -num;
	}
	
	while ( clone != 0 )
	{
		count++;
		clone /= 7;
	}
	char* str = (char*)malloc((count + 1)*sizeof(char));
	str[count] = '\0';
	clone = num;
	if ( !flag )
	{
		clone = -num;
		str[0] = '-';
	}
	int mod = 0;
	while ( clone != 0 )
	{
		count--;
		mod = clone % 7;
		str[count] = '0' + mod;
		clone /= 7;
	}
	return str;
}

int main()
{
	convertToBase7(-7);
	return 0;
}