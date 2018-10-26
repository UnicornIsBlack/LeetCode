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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if ( l1 == NULL )
			return l2;
		if ( l2 == NULL )
			return l1;
		if ( l1 == NULL && l2 == NULL )
			return NULL;
		int carry = 0;
		ListNode* result = new ListNode(0);
		ListNode* node = result;
		ListNode* n1 = l1;
		ListNode* n2 = l2;
		while ( n1 != NULL && n2 != NULL )
		{
			int sum = n1->val + n2->val + carry;
			ListNode* n = new ListNode(sum % 10);
			carry = sum / 10;
			node->next = n;
			node = node->next;
			n1 = n1->next;
			n2 = n2->next;
		}
		if ( n1 == NULL )
		{
			while ( n2 != NULL )
			{
				int sum = n2->val + carry;
				ListNode* n = new ListNode(sum % 10);
				carry = sum / 10;
				node->next = n;
				node = n;
				n2 = n2->next;
			}
		}
		if ( n2 == NULL )
		{
			while ( n1 != NULL )
			{
				int sum = n1->val + carry;
				ListNode* n = new ListNode(sum % 10);
				carry = sum / 10;
				node->next = n;
				node = n;
				n1 = n1->next;
			}
		}
		if ( carry == 1 )
		{
			ListNode* n = new ListNode(carry);
			node->next = n;
		}
		return result->next;
	}
};

int main()
{
	return 0;
}