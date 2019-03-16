#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int integerBreak(int n)
	{
		vector<int> breaks(n + 1, 0);
		breaks[1] = 1;
		for ( int i = 2; i <= n; i++ )
		{
			int maxNum = 1;
			for ( int j = 1; j <= i / 2; j++ )
			{
				maxNum = max(maxNum, max(j*(i - j), max(j*breaks[i - j], breaks[j] * (i - j))));
			}
			breaks[i] = maxNum;
		}
		return breaks[n];
	}
};

int main()
{
	return 0;
}