#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> sortArrayByParityII(vector<int>& A)
	{
		int i = 0, j = 1;
		while ( i < A.size() && j < A.size() )
		{
			while ( i < A.size() && A[i] % 2 == 0 )
				i += 2;
			while ( j < A.size() && A[j] % 2 == 1 )
				j += 2;
			if ( i < A.size() && j < A.size() )
			{
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
		return A;
	}
};

int main()
{
	return 0;
}