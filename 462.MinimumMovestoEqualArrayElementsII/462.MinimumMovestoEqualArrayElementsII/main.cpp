#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minMoves2(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int mid = nums[n / 2];
		int res = 0;
		for ( int i = 0; i < n; i++ )
		{
			res += abs(nums[i] - mid);
		}
		return res;
	}
};

int main()
{
	return 0;
}