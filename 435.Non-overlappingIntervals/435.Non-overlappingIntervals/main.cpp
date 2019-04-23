#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		int res = 0, n = intervals.size(), last = 0;
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
		for ( int i = 1; i < n; ++i )
		{
			if ( intervals[i][0] < intervals[last][1] )
			{
				++res;
				if ( intervals[i][1] < intervals[last][1] ) last = i;
			}
			else
			{
				last = i;
			}
		}
		return res;
	}
}; 

int main()
{
	return 0;
}