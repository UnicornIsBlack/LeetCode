#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		vector<vector<int>> indexs;
		for ( int i = 0; i < matrix.size(); i++ )
		{
			for ( int j = 0; j < matrix[0].size(); j++ )
			{
				if ( matrix[i][j] == 0 )
				{
					vector<int> index = { i, j };
					indexs.push_back(index);
				}

			}
		}

		for ( int m = 0; m < indexs.size(); m++ )
		{
			int row = indexs[m][0];
			int col = indexs[m][1];
			for ( int i = 0; i < matrix.size(); i++ )
				matrix[i][col] = 0;
			for ( int j = 0; j < matrix[0].size(); j++ )
				matrix[row][j] = 0;
		}
	}
};

int main()
{
	return 0;
}