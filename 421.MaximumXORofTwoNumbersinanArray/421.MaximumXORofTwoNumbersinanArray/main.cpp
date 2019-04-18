#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int findMaximumXOR(vector<int>& nums)
	{
		int max = 0;
		int mask = 0;
		for ( int i = 31; i >= 0; i-- )
		{
			mask = mask | (1 << i);

			set<int> nSet;
			for ( int num : nums )
				nSet.insert(num&mask);

			int tmp = max | (1 << i);
			for ( int prefix : nSet )
			{
				if ( nSet.find(tmp ^ prefix) != nSet.end() )
				{
					max = tmp;
					break;
				}
			}
		}
		return max;
	}
};

int main()
{
	return 0;
}