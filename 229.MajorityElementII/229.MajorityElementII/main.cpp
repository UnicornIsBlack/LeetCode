#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> majorityElement(vector<int>& nums)
	{
		vector<int> res;
		int limit = nums.size() / 3;
		if ( nums.size() == 0 )
			return res;
		map<int, int> numsMap;
		for ( int i = 0; i < nums.size(); i++ )
		{
			numsMap[nums[i]]++;
		}
		for ( auto it = numsMap.begin(); it != numsMap.end(); it++ )
		{
			if ( it->second > limit )
				res.push_back(it->first);
		}
		return res;
	}
};

int main()
{
	return 0;
}