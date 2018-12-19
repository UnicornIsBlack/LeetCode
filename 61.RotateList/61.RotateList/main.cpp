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
	ListNode* rotateRight(ListNode* head, int k)
	{
		int len = 0;
		ListNode* node = head;
		ListNode* end;
		while ( node != NULL )
		{
			len++;
			end = node;
			node = node->next;
		}
		if ( len < 2 )
			return head;
		k = k%len;
		if ( k == 0 )
			return head;
		ListNode* newEnd = head;
		int endCount = len - k;
		while ( endCount > 1 )
		{
			newEnd = newEnd->next;
			endCount--;
		}
		ListNode* newHead = newEnd->next;
		newEnd->next = end->next;
		end->next = head;
		head = newHead;
		return head;
	}
};

int main()
{
	return 0;
}