#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void rotate(vector<vector<int>>& matrix)
	{
		int len = matrix.size();
		for ( int i = 0; i < len; i++ )
		{
			for ( int j = 0; j < len - i; j++ )
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[len - 1 - j][len - 1 - i];
				matrix[len - 1 - j][len - 1 - i] = tmp;
			}
		}
		for ( int i = 0; i < len / 2; i++ )
		{
			for ( int j = 0; j < len; j++ )
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[len - 1 - i][j];
				matrix[len - 1 - i][j] = tmp;
			}
		}
	}
	/*
	** 1:A[i][j] ==> A[j][len-1-i];
	** 2:·­×ª
	*/
};

int main()
{
	return 0;
}