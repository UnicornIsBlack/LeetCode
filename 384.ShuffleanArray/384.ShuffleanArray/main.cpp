#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	Solution(vector<int> nums)
	{
		this->nums = vector<int>(nums.begin(), nums.end());
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		vector<int> res(nums.begin(), nums.end());
		int len = nums.size();
		for ( int i = 0; i < len; i++ )
		{
			int pos = rand() % (len - i);
			int tmp = res[i];
			res[i] = res[pos + i];
			res[pos + i] = tmp;
		}
		return res;
	}
	private:
	vector<int> nums;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

int main()
{
	return 0;
}