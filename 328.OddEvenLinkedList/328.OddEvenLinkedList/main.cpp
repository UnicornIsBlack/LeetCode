#include <iostream>
#include <string>
#include <vector>
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
	ListNode* oddEvenList(ListNode* head)
	{
		if ( !head )
			return head;
		ListNode* odd = head;
		ListNode* even;
		ListNode* node = head->next;
		int count = 0;
		ListNode* o = odd;
		ListNode* e;
		while ( node != NULL )
		{
			count++;
			ListNode* n = node;
			node = node->next;
			n->next = NULL;
			if ( count % 2 == 0 )
			{
				if ( !even )
				{
					even = n;
					e = even;
				}
				else
				{
					e->next = n;
					e = e->next;
				}
			}
			else
			{
				o->next = n;
				o = o->next;
			}
		}
		o->next = even;
		return odd;
	}
};

int main()
{
	return 0;
}