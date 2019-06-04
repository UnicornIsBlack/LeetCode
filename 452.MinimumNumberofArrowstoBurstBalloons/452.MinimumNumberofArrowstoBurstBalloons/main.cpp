#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int findMinArrowShots(vector<vector<int>>& points)
	{
		if ( points.size() == 0 )
			return 0;
		sort(points.begin(), points.end());

		int res = 1;
		int end = points[0][1];
		for ( int i = 1; i < points.size(); i++ )
		{
			if ( points[i][0] <= end )
				end = min(end, points[i][1]);
			else
			{
				res++;
				end = points[i][1];
			}
				
		}
		return res;
	}
};

int main()
{
	return 0;
}