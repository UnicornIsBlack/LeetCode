#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
	void reorderList(ListNode* head)
	{
		if ( !head )
			return;
		stack<ListNode*> listStack;
		queue<ListNode*> listQueue;
		ListNode* node = head;
		int len = 0;
		while ( node != NULL )
		{
			node = node->next;
			len++;
		}
		node = head;
		int count = 1;
		while ( node != NULL )
		{
			if ( count > len/2 + 1 )
				listStack.push(node);
			if ( count <= len/2 + 1 )
				listQueue.push(node);
			node = node->next;
			count++;
		}
		ListNode* newHead = NULL;
		ListNode* end = NULL;
		while ( !listQueue.empty() || !listStack.empty() )
		{
			ListNode* queueNode = NULL;
			ListNode* stackNode = NULL;
			if ( !listQueue.empty() )
			{
				queueNode = listQueue.front();
				listQueue.pop();
				if ( !newHead )
				{
					newHead = queueNode;
					end = newHead;
				}
				end->next = queueNode;
				end = end->next;
			}
			if ( !listStack.empty() )
			{
				stackNode = listStack.top();
				listStack.pop();
				end->next = stackNode;
				end = end->next;
			}
		}
		end->next = NULL;
		head = newHead;
	}
};

int main()
{
	return 0;
}