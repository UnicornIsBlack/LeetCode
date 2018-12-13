#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		bool flag = true;
		for ( int i = 0; i < 9; i += 3 )
		{
			for ( int j = 0; j < 9; j += 3 )
			{
				if ( !isSudoku(board, i, j) )
					return false;
			}
		}

		for ( int i = 0; i < 9; i++ )
		{
			if ( !isSudokuRow(board, i) )
				return false;
		}

		for ( int i = 0; i < 9; i++ )
		{
			if ( !isSudokuCol(board, i) )
				return false;
		}
		return flag;
	}
	bool isSudokuRow(vector<vector<char>>& board, int row)
	{
		vector<int> num(10, 0);
		for ( int i = 0; i < 9; i++ )
		{
			if ( board[row][i] == '.' )
				continue;
			int index = board[row][i] - '0';
			num[index]++;
			if ( num[index] > 1 )
				return false;
		}
		return true;
	}
	bool isSudokuCol(vector<vector<char>>& board, int col)
	{
		vector<int> num(10, 0);
		for ( int i = 0; i < 9; i++ )
		{
			if ( board[i][col] == '.' )
				continue;
			int index = board[i][col] - '0';
			num[index]++;
			if ( num[index] > 1 )
				return false;
		}
		return true;
	}
	bool isSudoku(vector<vector<char>>& board, int row, int col)
	{
		vector<int> num(10, 0);
		for ( int i = row; i < row + 3; i++ )
		{
			for ( int j = col; j < col + 3; j++ )
			{
				if ( board[i][j] == '.' )
					continue;
				int index = board[i][j] - '0';
				num[index]++;
				if ( num[index] > 1 )
					return false;
			}
		}
		return true;
	}

	/*
	bool isValidSudoku(vector<vector<char> > &board)
	{
		for ( int i = 0; i < 9; i++ )
		{
			unordered_map<char, bool> m1;   //check i_th row
			unordered_map<char, bool> m2;   //check i_th column
			unordered_map<char, bool> m3;   //check i_th subgrid
			for ( int j = 0; j < 9; j++ )
			{
				if ( board[i][j] != '.' )
				{
					if ( m1[board[i][j]] == true )
						return false;
					m1[board[i][j]] = true;
				}
				if ( board[j][i] != '.' )
				{
					if ( m2[board[j][i]] == true )
						return false;
					m2[board[j][i]] = true;
				}
				if ( board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.' )
				{
					if ( m3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]] == true )
						return false;
					m3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]] = true;
				}
			}
		}
		return true;
	}
	*/
};

int main()
{
	return 0;
}