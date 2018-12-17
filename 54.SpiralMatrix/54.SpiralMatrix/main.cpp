#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> result;
		if ( matrix.size() == 0 )
			return result;
		int row = matrix.size();
		int col = matrix[0].size();
		int len = min(row, col);
		int mid = len / 2;
		if ( len % 2 == 1 )
			mid++;

		for ( int k = 0; k < mid; k++ )
		{
			int i = k;
			int j = k;
			for ( j = k; j < col - k; j++ )
			{
				result.push_back(matrix[i][j]);
			}
			j = col - 1 - k;
			for ( i = k + 1; i < row - k; i++ )
			{
				result.push_back(matrix[i][j]);
			}
			i = row - 1 - k;
			if ( i > k )
			{
				for ( j = col - 2 - k; j >= k; j-- )
				{
					result.push_back(matrix[i][j]);
				}
			}
			j = k;
			if ( j == col - 1 - k )
				continue;
			for ( i = row - 2 - k; i > k; i-- )
			{
				result.push_back(matrix[i][j]);
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}