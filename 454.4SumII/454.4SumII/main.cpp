#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		map<int,int> sumMap;
		int res = 0;
		for ( int i = 0; i < A.size(); i++ )
		{
			for ( int j = 0; j < B.size(); j++ )
			{
				sumMap[-(A[i] + B[j])]++;
			}
		}
		for ( int i = 0; i < C.size(); i++ )
		{
			for ( int j = 0; j < D.size(); j++ )
			{
				int sum = C[i] + D[j];
				res += sumMap[sum];
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}