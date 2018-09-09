#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution
{
	public:
	int smoother(vector<vector<int>> smooth, int i, int j)
	{
		int row = smooth.size();
		int col = smooth[0].size();
		double sum = smooth[i][j];
		int count = 1;
		switch ( 1 )
		{
			case 1://L
				if ( j - 1 >= 0 )
				{
					sum += smooth[i][j - 1];
					count++;
				}
			case 2://LD
				if ( j - 1 >= 0 && i + 1 < row )
				{
					sum += smooth[i + 1][j - 1];
					count++;
				}
			case 3://D
				if ( i + 1 < row )
				{
					sum += smooth[i + 1][j];
					count++;
				}
			case 4://RD
				if ( i + 1 < row && j + 1 < col )
				{
					sum += smooth[i + 1][j + 1];
					count++;
				}
			case 5://R
				if ( j + 1 < col )
				{
					sum += smooth[i][j + 1];
					count++;
				}
			case 6://RU
				if ( j + 1 < col && i - 1 >= 0 )
				{
					sum += smooth[i - 1][j + 1];
					count++;
				}
			case 7://U
				if ( i - 1 >= 0 )
				{
					sum += smooth[i - 1][j];
					count++;
				}
			case 8://LU
				if ( i - 1 >= 0 && j - 1 >= 0 )
				{
					sum += smooth[i - 1][j - 1];
					count++;
				}

			default:
				break;
		}
		return sum / count;
	}
	vector<vector<int>> imageSmoother(vector<vector<int>>& M)
	{
		int rowNum = M.size();
		int colNum = M[0].size();
		vector<vector<int>> smooth(rowNum, vector<int>(colNum, 0));
		for ( int i = 0; i < rowNum; i++ )
		{
			for ( int j = 0; j < colNum; j++ )
			{
				smooth[i][j] = smoother(M, i, j);
			}
		}
		return smooth;
	}
};


int main()
{
	return 0;
}