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
		dfs(head);
		return head;
	}

	Node* dfs(Node* head)
	{
		if ( !head )
			return head;
		Node* node = head;
		Node* end = node;
		while ( node != NULL )
		{
			end = node;
			if ( node->child != NULL )
			{
				Node* childEnd = dfs(node->child);
				Node* next = node->next;
				if ( next == NULL )
				{
					node->next = node->child;
					node->next->prev = node;
					node->child = NULL;
					childEnd->next = NULL;
					node = childEnd;
				}
				else
				{
					node->next = node->child;
					node->child = NULL;
					node->next->prev = node;
					childEnd->next = next;
					next->prev = childEnd;
					node = next;
				}
			}
			else
				node = node->next;
		}
		return end;
	}
};

int main()
{
	return 0;
}