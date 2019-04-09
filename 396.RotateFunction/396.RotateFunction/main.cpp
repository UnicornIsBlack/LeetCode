#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maxRotateFunction(vector<int>& A)
	{
		if ( A.size() <= 1 )
			return 0;
		int res = -2147483648;
		for ( int i = 0; i < A.size(); i++ )
		{
			res = max(res, function(A));
			int end = A.back();
			A.pop_back();
			A.insert(A.begin(), end);
		}
		return res;
	}

	int function(vector<int>& nums)
	{
		int sum = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			sum += (i*nums[i]);
		}
		return sum;
	}
};

int main()
{
	return 0;
}