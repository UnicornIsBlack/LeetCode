#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> result(n,vector<int>(n, 0));
		int num = 1;
		int square = n*n;
		int rowBegin = 0, rowEnd = n - 1;
		int colBegin = 0, colEnd = n - 1;
		while ( num <= square )
		{
			for ( int i = colBegin; i <= colEnd; i++ )
			{
				result[rowBegin][i] = num;
				num++;
			}
			rowBegin++;
			for ( int i = rowBegin; i <= rowEnd; i++ )
			{
				result[i][colEnd] = num;
				num++;
			}
			colEnd--;
			for ( int i = colEnd; i >= colBegin; i-- )
			{
				result[rowEnd][i] = num;
				num++;
			}
			rowEnd--;
			for ( int i = rowEnd; i >= rowBegin; i-- )
			{
				result[i][colBegin] = num;
				num++;
			}
			colBegin++;
		}
		return result;
	}
};

int main()
{
	return 0;
}