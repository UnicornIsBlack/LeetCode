#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int countNumbersWithUniqueDigits(int n)
	{
		if ( n == 0 )
			return 1;
		int res = 0;
		for ( int i = 1; i <= n; i++ )
			res += count(i);
		return res;
	}

	int count(int k)
	{
		if ( k == 1 )
			return 10;
		int res = 1;
		for ( int i = 1; i < k; i++ )
			res *= (10 - i);
		return res * 9;
	}
};

int main()
{
	return 0;
}