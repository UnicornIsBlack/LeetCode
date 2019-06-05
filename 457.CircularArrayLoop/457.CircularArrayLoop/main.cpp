#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool circularArrayLoop(vector<int>& nums)
	{
		int n = nums.size();
		vector<bool> visited(n, false);
		for ( int i = 0; i < n; i++ )
		{
			if ( visited[i] )
				continue;
			int cur = i;
			visited[i] = true;
			unordered_map<int, int> m;
			while ( true )
			{
				int next = ((cur + nums[cur]) % n + n) % n;
				if ( next == cur || nums[cur] * nums[next] < 0 )
					break;
				if ( m.count(next) )
					return true;
				m[cur] = next;
				cur = next;
				visited[next] = true;
			}
		}
		return false;
	}
};


int main()
{
	return 0;
}