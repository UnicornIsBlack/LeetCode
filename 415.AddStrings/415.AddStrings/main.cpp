#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int n = 0;
	if ( len1 < len2 )
		n = len2 + 1;
	else
		n = len1 + 1;
	char* sum = (char*)malloc((n + 1)*sizeof(char));
	sum[n] = '\0';
	for ( int k = 0; k<n; k++ )
	{
		sum[k] = '0';
	}
	int i = len1 - 1;
	int j = len2 - 1;
	int k = n - 1;
	while ( i >= 0 && j >= 0 )
	{
		int iVal = num1[i] - '0';
		int jVal = num2[j] - '0';
		int sVal = sum[k] - '0';
		int sumVal = iVal + jVal + sVal;
		if ( sumVal >= 10 )
		{
			sum[k] = '0' + (sumVal - 10);
			sum[k - 1] += 1;
		}
		else
			sum[k] = '0' + sumVal;
		i--;
		j--;
		k--;
	}
	while ( i >= 0 )
	{
		int iVal = num1[i] - '0';
		int sVal = sum[k] - '0';
		int sumVal = iVal + sVal;
		if ( sumVal >= 10 )
		{
			sum[k] = '0' + (sumVal - 10);
			sum[k - 1] += 1;
		}
		else
			sum[k] = '0' + sumVal;
		i--;
		k--;
	}
	while ( j >= 0 )
	{
		int jVal = num2[j] - '0';
		int sVal = sum[k] - '0';
		int sumVal = jVal + sVal;
		if ( sumVal >= 10 )
		{
			sum[k] = '0' + (sumVal - 10);
			sum[k - 1] += 1;
		}
		else
			sum[k] = '0' + sumVal;
		j--;
		k--;
	}
	if ( sum[0] == '0' )
		return sum + 1;
	return sum;
}

int main()
{
	return 0;
}