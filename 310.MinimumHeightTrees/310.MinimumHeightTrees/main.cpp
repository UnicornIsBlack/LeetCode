#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
	{
		if ( n == 0 )
			return{};
		if ( n == 1 )
			return{ 0 };
		map<int, set<int>> graph;
		for ( int i = 0; i < n; i++ )
			graph[i] = set<int>();
		for ( pair<int, int> edge : edges )
		{
			graph[edge.first].insert(edge.second);
			graph[edge.second].insert(edge.first);
		}
		vector<int> leaves;
		for ( int i = 0; i < n; i++ )
		{
			if ( graph[i].size() == 1 )
				leaves.push_back(i);
		}

		while ( n > 2 )
		{
			n -= leaves.size();
			vector<int> newLeaves;
			for ( int leaf : leaves )
			{
				for ( int newLeaf : graph[leaf] )
				{
					graph[leaf].erase(newLeaf);
					graph[newLeaf].erase(leaf);
					if ( graph[newLeaf].size() == 1 )
						newLeaves.push_back(newLeaf);
				}
			}
			leaves = newLeaves;
		}
		return leaves;
	}
};

int main()
{
	return 0;
}