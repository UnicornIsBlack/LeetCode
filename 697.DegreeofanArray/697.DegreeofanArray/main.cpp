#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Solution
{
	public:
	int findShortestSubArray(vector<int>& nums)
	{
		map<int, vector<int>> mapIndex;
		int maxCount = 0;
		int minLen = INT_MAX;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( mapIndex.count(nums[i]) )
			{
				mapIndex[nums[i]][1] = i;
				mapIndex[nums[i]][2]++;
			}
			else
			{
				vector<int> index(3, 0);
				index[0] = i;
				index[1] = i;
				index[2] = 1;
				mapIndex[nums[i]] = index;
			}
			maxCount = max(maxCount, mapIndex[nums[i]][2]);
		}

		map<int, vector<int>>::iterator it;
		it = mapIndex.begin();
		while ( it != mapIndex.end() )
		{
			if ( it->second[2] == maxCount )
				minLen = min(minLen, it->second[1] - it->second[0] + 1);
			it++;
		}
		return minLen;
	}
};

int main()
{
	return 0;
}