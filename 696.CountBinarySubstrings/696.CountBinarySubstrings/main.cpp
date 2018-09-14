#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int countBinarySubstrings(string s)
	{
		vector<int> nums;
		nums.push_back(1);
		int index = 0;
		int count = 0;
		for ( int i = 0; i < s.size() - 1; i++ )
		{
			if ( s[i] != s[i + 1] )
			{
				index++;
				nums.push_back(1);
			}
			else
				nums[index]++;
		}
		for ( int i = 0; i < nums.size() - 1; i++ )
		{
			count += min(nums[i], nums[i + 1]);
		}
		return count;
	}
};

int main()
{
	Solution s;
	cout << s.countBinarySubstrings("00110011") << endl;
	return 0;
}