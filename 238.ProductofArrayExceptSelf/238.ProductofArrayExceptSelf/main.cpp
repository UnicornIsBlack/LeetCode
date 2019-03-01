#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		vector<int> res;
		if ( nums.size() == 0 )
			return res;
		int mul = 1;
		int count = 0;
		int index = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( nums[i] == 0 )
			{
				index = i;
				count++;
				continue;
			}
			mul *= nums[i];
		}
		if ( count > 0 )
		{
			res = vector<int>(nums.size(), 0);
			if ( count == 1 )
				res[index] = mul;
			return res;
		}
		else
		{
			for ( int i = 0; i < nums.size(); i++ )
			{
				res.push_back(mul/nums[i]);
			}
		}
		
		return res;
	}
};

int main()
{
	return 0;
}