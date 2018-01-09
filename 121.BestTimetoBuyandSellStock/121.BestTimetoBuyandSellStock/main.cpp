#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize)
{
	int profit = 0;
	int newProfit = 0;
	for ( int i = 1; i < pricesSize; i++ )
	{
		newProfit += (prices[i] - prices[i - 1]);
		if ( profit < newProfit )
		{
			profit = newProfit;
		}
		if ( newProfit < 0 )
		{
			newProfit = 0;
		}
	}
	return profit;
}

int main()
{
	int prices[] = { 7, 1, 5, 3, 6, 4 };/*prices[4] - prices[1] = ( prices[4] - prices[3] ) + ( prices[3] - prices[2] ) + ( prices[2] - prices[1] )*/
	int pricesSize = 6;
	int max = maxProfit(prices, pricesSize);
	printf("%d\n", max);
	return 0;
}