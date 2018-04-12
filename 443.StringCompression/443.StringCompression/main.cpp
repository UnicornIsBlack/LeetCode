#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compress(char* chars, int charsSize)
{
	int count = 0;
	int k = 0;
	for ( int i = 0; i < charsSize; )
	{
		int sCount = 1;
		for ( int j = i + 1; j < charsSize; j++ )
		{
			if ( chars[j] == chars[i] )
				sCount++;
			else
				break;
		}
		if ( sCount == 1 )
		{
			chars[k] = chars[i];
			k++;
			count++;
		}
		else
		{
			int bit = 0;
			int val = sCount;
			while ( val != 0 )
			{
				bit++;
				val /= 10;
			}
			int*  bitNum = (int*)malloc(bit*sizeof(int));
			val = sCount;
			for ( int i = bit - 1; i >= 0; i-- )
			{
				bitNum[i] = val % 10;
				val /= 10;
			}
			chars[k] = chars[i];
			k++;
			count++;
			for ( int i = 0; i < bit; i++, k++ )
			{
				chars[k] = '0' + bitNum[i];
				count++;
			}
		}
		i += sCount;
	}
	return count;
}

int main()
{
	return 0;
}