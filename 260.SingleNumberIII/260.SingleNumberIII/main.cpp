#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> singleNumber(vector<int>& nums)
	{
		vector<int> res;
		int xorFlag = 0;
		for ( int i = 0; i < nums.size(); i++ )
			xorFlag ^= nums[i];
		int flag = 0x01;
		while ( true )
		{
			if ( flag & xorFlag )
				break;
			flag <<= 1;
		}
		int res1 = 0, res2 = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( nums[i] & flag )
				res1 ^= nums[i];
			else
				res2 ^= nums[i];
		}
		res.push_back(res1);
		res.push_back(res2);
		return res;
	}
};

int main()
{
	return 0;
}