#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if ( board.size() == 0 )
			return false;
		if ( board[0].size() == 0 )
			return false;
		if ( word.empty() )
			return true;
		int row = board.size();
		int col = board[0].size();
		bool result = false;
		for ( int i = 0; i < row; i++ )
		{
			for ( int j = 0; j < col; j++ )
			{
				vector<vector<int>> move(row, vector<int>(col, 0));
				result = result || dsp(board, move, i, j, 0, word);
				if ( result )
					return true;
			}
		}
		return result;
	}
	bool dsp(vector<vector<char>>& board, vector<vector<int>>& move, int i, int j, int index, string& word)
	{
		if ( index == word.size() )
			return true;
		if ( move[i][j] == 1 )
			return false;
		bool result = false;
		if ( board[i][j] == word[index] )
		{
			if ( board.size() == 1 && board[0].size() == 1 && index == word.size() - 1 )
				return true;
			move[i][j] = 1;
			if ( j > 0 )
			{
				result = result || dsp(board, move, i, j - 1, index + 1, word);
			}
			if ( i < board.size() - 1 )
			{
				result = result || dsp(board, move, i + 1, j, index + 1, word);
			}
			if ( j < board[0].size() - 1 )
			{
				result = result || dsp(board, move, i, j + 1, index + 1, word);
			}
			if ( i > 0 )
			{
				result = result || dsp(board, move, i - 1, j, index + 1, word);
			}
			move[i][j] = 0;
		}
		return result;
	}
};

int main()
{
	return 0;
}