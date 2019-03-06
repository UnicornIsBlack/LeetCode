#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numSquares(int n)
	{
		vector<int> counts(n + 1, 0);
		int s = sqrt(n);
		for ( int i = 1; i <= s; i++ )
		{
			counts[i*i] = 1;
		}
		for ( int i = 1; i <= n; i++ )
		{
			if ( counts[i] != 0 )
				continue;
			int cs = sqrt(i);
			int minC = INT_MAX;
			for ( int j = cs; j >= 1; j-- )
			{
				if ( counts[i - j*j] != 0 )
				{
					minC = min(counts[i - j*j] + 1, minC);
				}
			}
			counts[i] = minC;
		}
		return counts[n];
	}
};

int main()
{
	return 0;
}