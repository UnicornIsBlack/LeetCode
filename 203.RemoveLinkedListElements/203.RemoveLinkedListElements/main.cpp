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
struct ListNode* removeElements(struct ListNode* head, int val)
{
	
	struct ListNode* freeNode;
	while ( head != NULL && head->val == val )
	{
		freeNode = head;
		head = head->next;
		free(freeNode);
	}
	if ( head == NULL )
		return head;
	struct ListNode* hClone = head;
	while ( hClone->next != NULL )
	{
		if ( hClone->next->val == val )
		{
			freeNode = hClone->next;
			hClone->next = freeNode->next;
			free(freeNode);
			continue;
		}
		else
		{
			hClone = hClone->next;
		}
	}
	return head;
}
int main()
{
	return 0;
}