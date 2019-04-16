#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
	{
		vector<pair<int, int>> res;
		if ( matrix.size() == 0 || matrix[0].size() == 0 )
			return res;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		queue<pair<int, int>> pQueue;
		queue<pair<int, int>> aQueue;
		for ( int i = 0; i < m; i++ )
		{
			pacific[i][0] = true;
			pQueue.push(make_pair(i, 0));
			atlantic[i][n - 1] = true;
			aQueue.push(make_pair(i, n - 1));
		}
		for ( int i = 0; i < n; i++ )
		{
			pacific[0][i] = true;
			pQueue.push(make_pair(0, i));
			atlantic[m - 1][i] = true;
			aQueue.push(make_pair(m - 1, i));
		}

		bbm(pacific, pQueue, matrix);
		bbm(atlantic, aQueue, matrix);

		for ( int i = 0; i < m; i++ )
		{
			for ( int j = 0; j < n; j++ )
			{
				if ( pacific[i][j] && atlantic[i][j] )
					res.push_back(make_pair(i, j));
			}
		}
		return res;
	}

	//Branch and Bound Method
	void bbm(vector<vector<bool>> &ocean, queue<pair<int, int>>& queue, vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		while ( !queue.empty() )
		{
			pair<int, int> index = queue.front();
			queue.pop();
			int i = index.first;
			int j = index.second;
			if ( j > 0 && !ocean[i][j - 1] && matrix[i][j] <= matrix[i][j - 1] )
			{
				ocean[i][j - 1] = true;
				queue.push(make_pair(i, j - 1));
			}
			if ( i < m - 1 && !ocean[i + 1][j] && matrix[i][j] <= matrix[i + 1][j] )
			{
				ocean[i + 1][j] = true;
				queue.push(make_pair(i + 1, j));
			}
			if ( j < n -1 && !ocean[i][j + 1] && matrix[i][j] <= matrix[i][j + 1] )
			{
				ocean[i][j + 1] = true;
				queue.push(make_pair(i, j + 1));
			}
			if ( i > 0 && !ocean[i - 1][j] && matrix[i][j] <= matrix[i - 1][j] )
			{
				ocean[i - 1][j] = true;
				queue.push(make_pair(i - 1, j));
			}
		}
	}
};

int main()
{
	return 0;
}