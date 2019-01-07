#include <iostream>
#include <string>
#include <vector>
#include <set>
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
	/* use fast point and slow poing */
	ListNode *detectCycle(ListNode *head)
	{
		if ( !head )
			return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		while ( fast != NULL && fast->next != NULL )
		{
			slow = slow->next;
			fast = fast->next->next;
			if ( slow == fast )
				break;
		}
		if ( fast == NULL || fast->next == NULL )
			return NULL;
		slow = head;
		while ( slow != fast )
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
	/* use set */
	/*ListNode *detectCycle(ListNode *head)
	{
		set<ListNode*> listSet;
		if ( !head )
			return NULL;
		ListNode* node = head;
		while ( node != NULL )
		{
			set<ListNode*>::iterator it;
			it = listSet.find(node);
			if ( it != listSet.end() )
			{
				return *it;
			}
			listSet.insert(node);
			node = node->next;
		}
		return NULL;
	}*/
};

int main()
{
	return 0;
}