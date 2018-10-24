#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		if ( A.size() <= 1 )
			return A;
		int i = 0, j = A.size() - 1;
		while ( i < j )
		{
			while ( i < j && A[i] % 2 == 0 )
				i++;
			while ( i < j && A[j] % 2 == 1 )
				j--;
			if ( i < j )
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