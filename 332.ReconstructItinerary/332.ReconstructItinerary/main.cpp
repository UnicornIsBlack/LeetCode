#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> findItinerary(vector<pair<string, string>> tickets)
	{
		vector<string> res;
		vector<pair<string, string>> copy(tickets.begin(), tickets.end());
		string start = "JFK";
		res.push_back(start);
		while ( tickets.size() != 0 )
		{
			string end = "";
			int index;
			for ( int i = 0; i < tickets.size(); i++ )
			{
				if ( tickets[i].first.compare(start) == 0 )
				{
					if ( end == "" || end.compare(tickets[i].second) > 0 )
					{
						end = tickets[i].second;
						index = i;
					}
				}
			}
			res.push_back(end);
			start = end;
			tickets.erase(tickets.begin() + index);
		}
		return res;
	}
};

int main()
{
	return 0;
}