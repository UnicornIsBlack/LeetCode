#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool find132pattern(vector<int>& nums)
	{
		int s2 = INT_MIN;
		stack<int> st;
		for ( int i = nums.size() - 1; i >= 0; i-- )
		{
			if ( nums[i] < s2 ) return true;
			while ( !st.empty() && nums[i] > st.top() )
			{
				s2 = st.top();
				st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
};

int main()
{
	return 0;
}