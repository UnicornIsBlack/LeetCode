#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> transpose(vector<vector<int>>& A)
	{
		int row = A.size();
		int col = A[0].size();
		vector<vector<int>> trans(col, vector<int>(row));

		for ( int i = 0; i < row; i++ )
		{
			for ( int j = 0; j < col; j++ )
			{
				trans[j][i] = A[i][j];
			}
		}

		return trans;
	}
};

int main()
{
	return 0;
}