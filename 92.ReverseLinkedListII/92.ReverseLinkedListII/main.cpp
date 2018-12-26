#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

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
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		stack<ListNode*> listStack;
		ListNode* node = head;
		ListNode* newHead = NULL;
		ListNode* end;
		int i = 1;
		while ( node != NULL )
		{
			if ( i >= m && i < n )
				listStack.push(node);
			else if ( i == n )
			{
				if ( !newHead )
				{
					newHead = node;
					end = newHead;
				}
				else
				{
					end->next = node;
					end = end->next;
				}
				node = node->next;
				while ( !listStack.empty() )
				{
					ListNode* tmp = listStack.top();
					listStack.pop();
					end->next = tmp;
					end = end->next;
				}
				continue;
			}
			else
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
			i++;
			node = node->next;
		}
		end->next = NULL;
		return newHead;
	}
};

int main()
{
	return 0;
}