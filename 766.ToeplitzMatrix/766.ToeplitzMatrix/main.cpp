#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		bool flag = true;
		for ( int i = 0; i < row; i++ )
		{
			if ( !flag )
				break;
			int value = matrix[i][0];
			for ( int m = i + 1, n = 1; m < row&&n < col; m++, n++ )
			{
				if ( matrix[m][n] != value )
				{
					flag = false;
					break;
				}
			}
		}
		for ( int j = 1; j < col; j++ )
		{
			if ( !flag )
				break;
			int value = matrix[0][j];
			for ( int m = 1, n = j + 1; m < row&&n < col; m++, n++ )
			{
				if ( matrix[m][n] != value )
				{
					flag = false;
					break;
				}
			}
		}
		return flag;
	}
};

int main()
{
	return 0;
}