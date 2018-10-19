#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
	{
		int aSum = 0;
		int bSum = 0;
		for ( int i = 0; i < A.size(); i++ )
		{
			aSum += A[i];
		}
		for ( int i = 0; i < B.size(); i++ )
		{
			bSum += B[i];
		}
		vector<int> result;
		bool flag = false;
		for ( int i = 0; i < A.size(); i++ )
		{
			for ( int j = 0; j < B.size(); j++ )
			{
				if ( aSum - A[i] + B[j] == bSum - B[j] + A[i] )
				{
					result.push_back(A[i]);
					result.push_back(B[j]);
					flag = true;
					break;
					
				}
			}
			if ( flag )
				break;
		}
		return result;
	}
};

int main()
{
	return 0;
}