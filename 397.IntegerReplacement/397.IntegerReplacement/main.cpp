#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int integerReplacement(int n)
	{
		if ( n == 0 )
			return 1;
		if ( n == 1 )
			return 0;
		if ( n == 2 )
			return 1;
		if ( n % 2 == 0 )
			return integerReplacement(n / 2) + 1;
		else if ( n == 2147483647 )
			return integerReplacement(n - 1);
		else
			return min(integerReplacement(n + 1) + 1, integerReplacement(n - 1) + 1);
	}
};

int main()
{
	return 0;
}