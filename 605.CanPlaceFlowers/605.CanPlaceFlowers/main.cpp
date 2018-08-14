#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int count = 0;
	for ( int i = 0; i < flowerbedSize; i++ )
	{
		if ( flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbedSize - 1 || flowerbed[i + 1] == 0) )
		{
			flowerbed[i] = 1;
			count++;
		}
	}
	return n <= count;
}

int main()
{
	return 0;
}