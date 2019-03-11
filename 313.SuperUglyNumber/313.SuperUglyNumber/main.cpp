#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		vector<int> indexs(primes.size(), 0);

		vector<int> num = { 1 };
		while ( num.size() < n )
		{
			int minNum = INT_MAX;
			for ( int i = 0; i < indexs.size(); i++ )
			{
				int next = num[indexs[i]] * primes[i];
				minNum = min(next, minNum);
			}
			num.push_back(minNum);
			for ( int i = 0; i < indexs.size(); i++ )
			{
				if ( num[indexs[i]] * primes[i] <= minNum )
					indexs[i]++;
			}
		}
		return num[n - 1];
	}
};

int main()
{
	return 0;
}