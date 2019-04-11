#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
	{
		vector<pair<int, int>> res;
		while ( people.size() > 0 )
		{
			int index = 0;
			pair<int, int> p = people[0];
			for ( int i = 1; i < people.size(); i++ )
			{
				if ( people[i].first > p.first || (people[i].first == p.first && people[i].second < p.second) )
				{
					p = people[i];
					index = i;
				}
			}
			people.erase(people.begin() + index);
			int i = p.second;
			res.insert(res.begin() + i, p);
		}
		return res;
		
	}
};

int main()
{
	return 0;
}