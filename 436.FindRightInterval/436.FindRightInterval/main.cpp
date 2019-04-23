#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> findRightInterval(vector<vector<int>>& intervals)
	{
		vector<int> res(intervals.size(), -1);

		for ( int i = 0; i < intervals.size(); i++ )
		{
			for ( int j = 0; j < intervals.size(); j++ )
			{
				if ( j == i )
					continue;
				if ( intervals[j][0] >= intervals[i][1] )
				{
					if ( res[i] == -1 || intervals[res[i]][0] > intervals[j][0] )
						res[i] = j;
				}
			}
		}

		return res;
	}
};

int main()
{
	return 0;
}