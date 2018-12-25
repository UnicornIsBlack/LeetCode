#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

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
	ListNode* partition(ListNode* head, int x)
	{
		if ( !head )
			return head;
		queue<ListNode*> listQueue;
		ListNode* newHead = NULL;
		ListNode* end = NULL;
		ListNode* node = head;
		while ( node != NULL )
		{
			if ( node->val < x )
			{
				if ( !newHead )
				{
					newHead = node;
					end = node;
				}
				else
				{
					end->next = node;
					end = end->next;
				}
			}
			else
				listQueue.push(node);
			node = node->next;
		}
		while ( !listQueue.empty() )
		{
			ListNode* tmp = listQueue.front();
			if ( !newHead )
			{
				newHead = tmp;
				end = tmp;
			}
			else
			{
				end->next = tmp;
				end = end->next;
			}
			listQueue.pop();
		}
		end->next = NULL;
		return newHead;
	}
};

int main()
{
	return 0;
}