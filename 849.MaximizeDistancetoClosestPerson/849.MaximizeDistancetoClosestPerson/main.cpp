#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maxDistToClosest(vector<int>& seats)
	{
		vector<int> index;
		int maxNum = 0;
		for ( int i = 0; i < seats.size(); i++ )
		{
			if ( seats[i] == 1 )
				index.push_back(i);
		}
		for ( int i = 0; i < index.size(); i++ )
		{
			if ( i == 0 && index[i] != 0 )
			{
				maxNum = max(maxNum, index[i]);
				continue;
			}
			int sub = index[i] - index[i - 1] - 1;

			maxNum = max(maxNum, sub / 2 + sub % 2);
		}
		if ( index[index.size() - 1] != seats.size() - 1 )
		{
			int a = seats.size() - 1 - index[index.size() - 1];
			maxNum = max(maxNum, a);
		}
		return maxNum;
	}
};

int main()
{
	return 0;
}