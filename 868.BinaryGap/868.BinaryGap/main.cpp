#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int binaryGap(int N)
	{
		vector<int> index;
		int num = N;
		for ( int i = 0; num != 0; i++ )
		{
			int n = num & 1;
			if ( n == 1 )
				index.push_back(i);
			num = num >> 1;
		}
		int maxDistance = 0;
		for ( int i = 0; i < index.size() - 1; i++ )
		{
			maxDistance = max(maxDistance, index[i + 1] - index[i]);
		}
		return maxDistance;
	}
};

int main()
{
	return 0;
}