#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> counts(amount + 1, 0);
		for ( int i = 1; i <= amount; i++ )
		{
			int minCount = -1;
			for ( int j = 0; j < coins.size(); j++ )
			{
				int index = i - coins[j];
				if ( index < 0 )
					continue;
				if ( counts[index] == -1 )
					continue;
				if ( minCount == -1 )
					minCount = counts[index] + 1;
				else
					minCount = min(minCount, counts[index] + 1);
			}
			counts[i] = minCount;
		}
		return counts[amount];
	}
};

int main()
{
	return 0;
}