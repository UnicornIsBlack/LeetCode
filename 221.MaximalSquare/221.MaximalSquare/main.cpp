#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if ( matrix.size() == 0 || matrix[0].size() == 0 )
			return 0;
		vector<vector<int>> mapping(matrix.size(), vector<int>(matrix[0].size(), 0));

		int res = 0;
		for ( int i = 0; i < matrix.size(); i++ )
		{
			for ( int j = 0; j < matrix[0].size(); j++ )
			{
				if ( matrix[i][j] == '1' )
				{
					mapping[i][j] = 1;
					if ( i > 0 && j > 0 )
						mapping[i][j] = min(mapping[i - 1][j - 1], min(mapping[i][j - 1], mapping[i - 1][j])) + 1;
					res = max(res, mapping[i][j]);
				}
			}
		}
		return res*res;
	}
};

int main()
{
	return 0;
}