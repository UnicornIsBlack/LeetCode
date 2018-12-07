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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* node = head;
		ListNode* r;
		ListNode* prev;
		stack<ListNode*> listStack;
		while ( node != NULL )
		{
			listStack.push(node);
			node = node->next;
		}
		int i = 0;
		while ( !listStack.empty() )
		{
			i++;
			if ( i == n )
			{
				r = listStack.top();
			}
			else if ( i == n + 1 )
			{
				prev = listStack.top();
			}
			listStack.pop();
		}
		if ( r == head )
			head = head->next;
		else
			prev->next = r->next;
		free(r);
		return head;
	}
};

int main()
{
	return 0;
}