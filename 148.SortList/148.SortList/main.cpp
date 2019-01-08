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
	ListNode* sortList(ListNode* head)
	{
		if ( head == NULL || head->next == NULL )
			return head;

		ListNode* fast = head->next;
		ListNode* slow = head;
		while ( fast != NULL && fast->next != NULL )
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* mid = slow->next;
		slow->next = NULL;

		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		return mergeLists(left, right);
	}

	ListNode* mergeLists(ListNode* left, ListNode* right)
	{
		if ( !left )
			return right;
		if ( !right )
			return left;
		ListNode* head = NULL;
		if ( left->val <= right->val )
		{
			head = left;
			left = left->next;
		}
		else
		{
			head = right;
			right = right->next;
		}
		head->next = NULL;
		ListNode* end = head;
		while ( left != NULL && right != NULL )
		{
			if ( left->val <= right->val )
			{
				end->next = left;
				left = left->next;
			}
			else
			{
				end->next = right;
				right = right->next;
			}
			end = end->next;
			end->next = NULL;
		}
		if ( !left )
			end->next = right;
		if ( !right )
			end->next = left;
		return head;
	}
};

int main()
{
	return 0;
}