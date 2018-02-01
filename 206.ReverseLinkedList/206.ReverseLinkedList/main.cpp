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

struct ListNode* reverseList(struct ListNode* head)
{
	if ( head == NULL )
		return head;

	struct ListNode* next;
	struct ListNode* prev;
	struct ListNode* now;
	prev = NULL;
	next = head;
	while ( next != NULL )
	{
		now = next;
		next = now->next;
		now->next = prev;
		prev = now;
	}
	return now;
}

int main()
{
	return 0;
}