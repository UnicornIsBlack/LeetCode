#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if ( head == NULL || head->next == NULL )
		return head;

	struct ListNode* prev = head;
	struct ListNode* now = prev->next;
	while ( now != NULL )
	{
		if ( now->val == prev->val )
		{
			prev->next = now->next;
			free(now);
			now = prev->next;
		}
		else
		{
			prev = now;
			now = prev->next;
		}
	}
	return head;

}

int main()
{
	return 0;
}