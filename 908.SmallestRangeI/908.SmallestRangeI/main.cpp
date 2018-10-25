#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int smallestRangeI(vector<int>& A, int K)
	{
		vector<int>::iterator it;
		it = max_element(A.begin(), A.end());
		int maxNum = *it;
		it = min_element(A.begin(), A.end());
		int minNum = *it;

		if ( maxNum - K <= minNum + K )
			return 0;
		else
			return maxNum - minNum - 2 * K;

	}
};

int main()
{
	return 0;
}