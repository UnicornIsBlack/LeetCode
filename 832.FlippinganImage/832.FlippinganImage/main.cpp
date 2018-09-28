#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
	{
		for ( int i = 0; i < A.size(); i++ )
		{
			int len = A[i].size();
			int mid = len / 2;
			if ( len % 2 == 1 )
				mid++;
			for ( int j = 0; j < mid; j++ )
			{
				int tmp = A[i][j];
				A[i][j] = A[i][len - 1 - j] ^ 1;
				A[i][len - 1 - j] = tmp ^ 1;
			}
		}
		return A;
	}
};

int main()
{
	return 0;
}