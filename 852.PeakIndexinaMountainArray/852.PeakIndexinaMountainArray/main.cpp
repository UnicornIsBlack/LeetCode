#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int peakIndexInMountainArray(vector<int>& A)
	{
		if ( A.size() < 3 )
			return 0;

		int index = 0;
		int maxNum = A[0];
		for ( int i = 0; i < A.size(); i++ )
		{
			if ( A[i] > maxNum )
			{
				index = i;
				maxNum = A[i];
			}
		}
		return index;
	}
};

int main()
{
	return 0;
}