#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class RecentCounter
{
	public:
	RecentCounter()
	{
		count = queue<int>();
	}

	int ping(int t)
	{
		count.push(t);
		while ( !count.empty() )
		{
			int front = count.front();
			if ( front >= t - 3000 && front <= t )
				break;
			else
				count.pop();
		}
		return count.size();
	}
	private:
	queue<int> count;
};

/**
* Your RecentCounter object will be instantiated and called as such:
* RecentCounter* obj = new RecentCounter();
* int param_1 = obj->ping(t);
*/