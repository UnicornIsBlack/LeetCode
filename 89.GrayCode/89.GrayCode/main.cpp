#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> grayCode(int n)//G(N) = B(n) XOR (B(n)/2)
	{
		vector<int> result;
		for ( int i = 0; i < 1 << n; i++ )
		{
			result.push_back(i ^ (i >> 1));
		}
		return result;
	}
};

int main()
{
	return 0;
}