#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int countBattleships(vector<vector<char>>& board)
	{
		int res = 0;
		for ( int i = 0; i < board.size(); i++ )
		{
			for ( int j = 0; j < board[0].size(); j++ )
			{
				if ( board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X') )
					continue;
				res++;
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}