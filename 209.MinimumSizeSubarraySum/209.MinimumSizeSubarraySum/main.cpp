#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int minLen = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			int sum = 0;
			for ( int j = i; j < nums.size(); j++ )
			{
				sum += nums[j];
				if ( sum >= s )
				{
					int len = j - i + 1;
					if ( minLen == 0 )
						minLen = len;
					else
						minLen = min(minLen, len);
					break;
				}
			}
		}
		return minLen;
	}
};

int main()
{
	return 0;
}