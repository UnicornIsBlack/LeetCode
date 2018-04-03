#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* non_negativeToHex(int num)
{
	char* hex = (char*)malloc(9 * sizeof(char));
	hex[8] = '\0';
	int mod = 0;
	int count = 7;
	if ( num == 0 )
	{
		hex[count] = '0';
		return hex + count;
	}
	while ( num != 0 )
	{
		mod = num % 16;
		if ( mod >= 10 )
			hex[count] = 'a' + (mod - 10);
		else
			hex[count] = '0' + mod;
		num /= 16;
		count--;
	}
	return hex + count + 1;

}

int hexToInt(char hex)
{
	int val = 0;
	if ( hex >= '0' && hex <= '9' )
		val = hex - '0';
	else
		val = hex - 'a' + 10;
	return val;
}
char* negativeToHex(int num)
{
	char* hexN = (char*)malloc(9 * sizeof(char));
	hexN[8] = '\0';
	for ( int i = 0; i < 8; i++ )
	{
		hexN[i] = 'f';
	}
	char* hex = non_negativeToHex(-num - 1);
	int hLen = strlen(hex);
	int i = 7;
	int j = hLen - 1;
	while ( j >= 0 )
	{
		int a = hexToInt(hexN[i]);
		int b = hexToInt(hex[j]);
		int sub = a - b;
		char hexTmp;
		if ( sub >= 10 )
		{
			hexTmp = 'a' + (sub - 10);
		}
		else
		{
			hexTmp = '0' + sub;
		}
		hexN[i] = hexTmp;
		i--;
		j--;
	}
	int count = 0;
	for ( int i = 0; i < 8; i++ )
	{
		if ( hexN[i] != '0' )
			break;
		count++;
	}
	return hexN + count;
}



char* toHex(int num)
{
	if ( num < 0 )
		return negativeToHex(num);
	else
		return non_negativeToHex(num);
}

int main()
{
	char* hex = toHex(-1);
	printf("%s\n", hex);
	return 0;
}