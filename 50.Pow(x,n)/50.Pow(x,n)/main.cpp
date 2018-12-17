#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	double myPow(double x, int n)
	{
		if ( n < 0 )
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}

	double power(double x, int n)
	{
		if ( n == 0 )
			return 1;

		double tmp = power(x, n / 2);
		if ( n % 2 == 0 )
			return tmp * tmp;
		else
			return tmp*tmp*x;
	}
};

int main()
{
	return 0;
}