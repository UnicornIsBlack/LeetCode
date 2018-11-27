#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minDeletionSize(vector<string>& A)
	{
		int count = 0;
		if ( A.size() == 1 )
			return 0;
		for ( int j = 0; j < A[0].size(); j++ )
		{
			for ( int i = 1; i < A.size(); i++ )
			{
				if ( A[i - 1][j] > A[i][j] )
				{
					count++;
					break;
				}
			}
		}
		return count;
	}
};

int main()
{
	return 0;
}