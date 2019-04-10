#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
	{
		vector<double> ret;
		unordered_map<string, vector<pair<string, double>>> adj;
		for ( int i = 0; i<equations.size(); i++ )
		{
			adj[equations[i].first].push_back({ equations[i].second, values[i] });
			adj[equations[i].second].push_back({ equations[i].first, 1.0 / values[i] });
		}

		for ( int i = 0; i<queries.size(); i++ )
		{
			if ( !adj.count(queries[i].first) )
			{
				ret.push_back(-1.0);
				continue;
			}
			bool isFound = false;
			queue<pair<string, double>> q;
			unordered_set<string> st;
			q.push({ queries[i].first, 1.0 });
			st.insert(queries[i].first);

			while ( !q.empty() )
			{
				string cur = q.front().first;
				double ratio = q.front().second;
				q.pop();
				if ( cur == queries[i].second )
				{
					isFound = true;
					ret.push_back(ratio);
					break;
				}
				for ( auto it : adj[cur] )
				{
					if ( st.count(it.first) ) continue;
					st.insert(it.first);
					q.push({ it.first, ratio * it.second });
				}
			}
			if ( !isFound ) ret.push_back(-1.0);
		}
		return ret;
	}

};

int main()
{
	return 0;
}