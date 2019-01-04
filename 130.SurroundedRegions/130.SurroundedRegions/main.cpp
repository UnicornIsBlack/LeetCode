#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void solve(vector<vector<char>>& board)
	{
		if ( board.size() == 0 || board[0].size() == 0 )
			return;
		int row = board.size();
		int col = board[0].size();
		vector<vector<bool>> isX(row, vector<bool>(col, false));
		for ( int j = 0; j < col; j++ )
		{
			if ( board[0][j] == 'O' && !isX[0][j] )
				dfs(board, isX, 0, j);
			if ( board[row - 1][j] == 'O' && !isX[row - 1][j] )
				dfs(board, isX, row - 1, j);
		}
		for ( int i = 0; i < row; i++ )
		{
			if ( board[i][0] == 'O' && !isX[i][0] )
				dfs(board, isX, i, 0);
			if ( board[i][col - 1] == 'O' && !isX[i][col - 1] )
				dfs(board, isX, i, col - 1);
		}

		for ( int i = 0; i < row; i++ )
		{
			for ( int j = 0; j < col; j++ )
			{
				if ( !isX[i][j] && board[i][j] == 'O' )
					board[i][j] = 'X';
			}
		}

	}

	void dfs(vector<vector<char>>& board, vector<vector<bool>>& isX, int i, int j)
	{
		if ( board[i][j] == 'X' || isX[i][j] )
			return;
		int row = board.size();
		int col = board[0].size();
		isX[i][j] = true;
		if ( j > 0 )
			dfs(board, isX, i, j - 1);
		if ( i < row - 1 )
			dfs(board, isX, i + 1, j);
		if ( j < col - 1 )
			dfs(board, isX, i, j + 1);
		if ( i > 0 )
			dfs(board, isX, i - 1, j);
	}
};

int main()
{
	return 0;
}