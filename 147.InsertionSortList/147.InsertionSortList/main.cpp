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
	ListNode* insertionSortList(ListNode* head)
	{
		if ( !head )
			return head;
		ListNode* next = head->next;
		head->next = NULL;
		while ( next != NULL )
		{
			ListNode* insert = next;
			next = next->next;
			insert->next = NULL;
			if ( head->val >= insert->val )
			{
				insert->next = head;
				head = insert;
			}
			else
			{
				ListNode* node = head;
				bool isInsert = false;
				while ( node->next != NULL )
				{
					if ( node->next->val >= insert->val )
					{
						isInsert = true;
						insert->next = node->next;
						node->next = insert;
						break;
					}
					node = node->next;
				}
				if ( !isInsert )
					node->next = insert;
			}
		}
		return head;
	}
};

int main()
{
	return 0;
}