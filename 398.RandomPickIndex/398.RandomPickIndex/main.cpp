#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	Solution(vector<int>& nums)
	{
		for ( int i = 0; i < nums.size(); i++ )
			indexsMap[nums[i]].push_back(i);
	}

	int pick(int target)
	{
		int res = -1;
		if ( indexsMap.find(target) == indexsMap.end() )
			return res;
		vector<int> indexs = indexsMap[target];
		int n = rand() % indexs.size();
		res = indexs[n];
		return res;
	}
	private:
	map<int, vector<int>> indexsMap;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* int param_1 = obj->pick(target);
*/

int main()
{
	return 0;
}