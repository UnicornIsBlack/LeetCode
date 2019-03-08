#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NumMatrix
{
	public:
	NumMatrix(vector<vector<int>> matrix)
	{
		if ( matrix.size() == 0 || matrix[0].size() == 0 )
			return;
		nums = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
		for ( int i = 0; i < matrix.size(); i++ )
		{
			for ( int j = 0; j < matrix[0].size(); j++ )
			{
				nums[i][j] = matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		if ( nums.size() == 0 || nums[0].size() == 0 )
			return 0;
		int sum = 0;
		for ( int i = row1; i <= row2 && i < nums.size(); i++ )
		{
			for ( int j = col1; j <= col2 && j < nums[0].size(); j++ )
			{
				sum += nums[i][j];
			}
		}
		return sum;
	}
	private:
	vector<vector<int>> nums;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/

int main()
{
	return 0;
}