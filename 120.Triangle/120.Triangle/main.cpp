#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int row = triangle.size();
		if ( row == 0 )
			return 0;
		vector<int> minimum(triangle[row - 1].begin(), triangle[row - 1].end());

		for ( int i = row - 2; i >= 0; i-- )
		{
			for ( int j = 0; j < triangle[i].size(); j++ )
				minimum[j] = triangle[i][j] + min(minimum[j], minimum[j + 1]);
		}
		return minimum[0];
	}
};

int main()
{
	return 0;
}