#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void gameOfLife(vector<vector<int>>& board)
	{
		if ( board.size() == 0 || board[0].size() == 0 )
			return;
		for ( int i = 0; i < board.size(); i++ )
		{
			for ( int j = 0; j < board[0].size(); j++ )
			{
				int count = lifeNeihbor(board, i, j);
				if ( count == 2 )
					continue;
				else if ( count == 3 )
					board[i][j] = board[i][j] == 0 ? 3 : 1;
				else
					board[i][j] = board[i][j] == 1 ? 2 : 0;
			}
		}
		for ( int i = 0; i < board.size(); i++ )
		{
			for ( int j = 0; j < board[0].size(); j++ )
			{
				board[i][j] %= 2;
			}
		}
	}

	int lifeNeihbor(vector<vector<int>>& board, int m, int n)
	{
		int row = board.size();
		int col = board[0].size();
		int i = m - 1;
		int count = 0;
		if ( i < 0 )
			i = m;
		
		for ( ; i < row && i <= m + 1; i++ )
		{
			int j = n - 1;
			if ( j < 0 )
				j = n;
			for ( ; j < col && j <= n + 1; j++ )
			{
				if ( i == m && j == n )
					continue;
				if ( board[i][j] == 1 || board[i][j] == 2 )
					count++;
			}
		}
		return count;
	}

};

int main()
{
	return 0;
}