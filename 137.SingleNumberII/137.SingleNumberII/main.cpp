#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int singleNumber(vector<int>& nums)
	{
		if ( nums.size() == 0 )
			return -1;
		map<int, int> numMap;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( numMap.find(nums[i]) != numMap.end() )
				numMap[nums[i]]++;
			else
				numMap[nums[i]] = 1;
		}
		int result;
		for ( map<int, int>::iterator it = numMap.begin(); it != numMap.end(); it++ )
		{
			if ( it->second == 1 )
			{
				result = it->first;
				break;
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}