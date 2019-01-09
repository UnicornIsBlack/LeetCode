#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maxProduct(vector<int>& nums)
	{
		if ( nums.size() == 0 )
			return 0;
		vector<int> mul(nums.begin(), nums.end());
		int maxNum = mul[0];
		vector<int> res(nums.size() - 1, 0);
		for ( int i = 0; i < nums.size(); i++ )
		{
			maxNum = max(maxNum, nums[i]);
			if ( i != 0 )
			{
				res[i - 1] = nums[i] * nums[i - 1];
				maxNum = max(maxNum, res[i - 1]);
			}
		}
		while ( res.size() > 1 )
		{
			vector<int> result(res.size() - 1, 0);
			for ( int i = 1; i < res.size(); i++ )
			{
				if ( mul[i] == 0 )
					result[i - 1] = 0;
				else
					result[i - 1] = res[i] / mul[i] * res[i - 1];
				maxNum = max(maxNum, result[i - 1]);
			}
			mul = res;
			res = result;
		}
		return maxNum;
	}
};

int main()
{
	return 0;
}