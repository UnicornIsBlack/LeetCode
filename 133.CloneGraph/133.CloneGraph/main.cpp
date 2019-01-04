#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
	public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		UndirectedGraphNode* res;
		map<int, UndirectedGraphNode*> table;
		res = clone(node, table);
		return res;
	}

	UndirectedGraphNode* clone(UndirectedGraphNode* node, map<int, UndirectedGraphNode*>& table)
	{
		if ( node == NULL )
			return NULL;
		if ( table.find(node->label) != table.end() )
			return table[node->label];

		UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		table[node->label] = newNode;
		for ( int i = 0; i < node->neighbors.size(); i++ )
		{
			UndirectedGraphNode* neighbor = clone(node->neighbors[i], table);
			newNode->neighbors.push_back(neighbor);
		}
		return newNode;
	}
};

int main()
{
	return 0;
}