#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for a Node.
class Node {
	public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution
{
	public:
	Node* flatten(Node* head)
	{
		if ( !head )
			return head;
		Node* node = head;
		while ( node != NULL )
		{
			if ( node->child != NULL )
			{

			}
			node = node->next;
		}
	}

	Node* dfs(Node* head)
	{
		
	}
};

int main()
{
	return 0;
}