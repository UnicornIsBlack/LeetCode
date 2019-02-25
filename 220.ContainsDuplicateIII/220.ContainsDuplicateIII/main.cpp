#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		if ( nums.size() == 0 )
			return false;
		multiset<long long> st;
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( i > k )
				st.erase(st.find(nums[i - k - 1]));
			auto it = st.lower_bound((long long)nums[i] - t);
			if ( it != st.end() && abs(*it - nums[i]) <= t )
				return true;
			st.insert(nums[i]);
		}
		return false;
	}
};

int main()
{
	return 0;
}