#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> findItinerary(vector<pair<string, string>> tickets)
	{
		unordered_map<string, multiset<string>> hash;
		for ( auto ticket : tickets )
			hash[ticket.first].insert(ticket.second);
		vector<string> res;
		stack<string> st;
		st.push("JFK");
		while ( !st.empty() )
		{
			string start = st.top();
			if ( hash.find(start) != hash.end() && hash[start].size() > 0 )
			{
				st.push(*hash[start].begin());
				hash[start].erase(hash[start].begin());
			}
			else
			{
				res.insert(res.begin(), start);
				st.pop();
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}