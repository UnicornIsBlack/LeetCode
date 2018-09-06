#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	double findMaxAverage(vector<int>& nums, int k)
	{
		double sum = accumulate(nums.begin(), nums.begin() + k, 0);
		double maxSum = sum;
		for ( int i = k; i < nums.size(); i++ )
		{
			sum = sum + nums[i] - nums[i - k];
			maxSum = max(maxSum, sum);
		}
		return maxSum / k;
	}
};

int main()
{
	return 0;
}