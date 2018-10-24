#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isMonotonic(vector<int>& A)
	{
		bool flag = true;
		int val = 0;
		for ( int i = 0; i < A.size() - 1; i++ )
		{
			int tmp = 0;
			if ( A[i] < A[i + 1] )
				tmp = -1;
			else if ( A[i] == A[i + 1] )
				tmp = 0;
			else if ( A[i] > A[i + 1] )
				tmp = 1;
			if ( tmp == 0 )
				continue;
			else if ( tmp == -val )
			{
				flag = false;
				break;
			}
			val = tmp;
		}
		return flag;
	}
};

int main()
{
	return 0;
}