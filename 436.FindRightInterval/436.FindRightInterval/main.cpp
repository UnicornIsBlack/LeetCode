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
		int n = intervals.size();
		vector<int> ans(n, -1);
		vector<pair<vector<int>, int>> h;

		for ( int i = 0; i < n; i++ )
			h.push_back(pair<vector<int>, int>(intervals[i], i));

		sort(h.begin(), h.end(), [](pair<vector<int>, int> a, pair<vector<int>, int> b)
		{
			return a.first[0] <= b.first[0] || (a.first[0] == b.first[0] && a.first[1] <= b.first[1]);
		});

		for ( int i = 0; i < n; i++ )
		{
			for ( int j = i + 1; j < n; j++ )
			{
				if ( h[j].first[0] >= h[i].first[1] )
				{
					ans[h[i].second] = h[j].second;
					break;
				}
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}