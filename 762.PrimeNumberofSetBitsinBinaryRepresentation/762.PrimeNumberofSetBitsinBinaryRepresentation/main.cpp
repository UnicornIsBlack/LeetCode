#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int countPrimeSetBits(int L, int R)
	{
		vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
		int count = 0;
		for ( int i = L; i <= R; i++ )
		{
			int setBits = setBitsCount(i);
			vector<int>::iterator it;
			it = find(primes.begin(), primes.end(), setBits);
			if ( it != primes.end() )
				count++;
		}
		return count;
	}
	int setBitsCount(int num)
	{
		int count = 0;
		while ( num != 0 )
		{
			count += (num & 1);
			num = num >> 1;
		}
		return count;
	}
};

int main()
{
	return 0;
}