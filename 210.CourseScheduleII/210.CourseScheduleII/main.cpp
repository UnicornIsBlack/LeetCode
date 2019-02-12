#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<pair<int, int>> copy(prerequisites.begin(), prerequisites.end());
		vector<int> incomings(numCourses, 0);
		vector<int> res;
		for ( int i = 0; i < prerequisites.size(); i++ )
			incomings[prerequisites[i].second]++;
		int index;
		while ( (index = isIncomingZero(incomings)) != -1 )
		{
			res.insert(res.begin(), index);
			incomings[index]--;
			for ( int i = 0; i < copy.size(); i++ )
			{
				if ( copy[i].first == index )
				{
					incomings[copy[i].second]--;
					copy.erase(copy.begin() + i);
					i--;
				}
			}
		}
		if ( copy.size() != 0 )
			return{};
		return res;
	}

	int isIncomingZero(vector<int>& incomings)
	{
		for ( int i = 0; i < incomings.size(); i++ )
		{
			if ( incomings[i] == 0 )
				return i;
		}
		return -1;
	}
};

int main()
{
	return 0;
}