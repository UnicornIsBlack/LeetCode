#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode node;
	struct ListNode* l;
	struct ListNode* r;
	struct ListNode* ln1;
	struct ListNode* ln2;
	l = &node;
	l->next = NULL;
	r = l;


	while ( l1 != NULL && l2 != NULL )
	{
		ln1 = l1;
		ln2 = l2;
		if ( l1->val < l2->val )
		{
			l1 = l1->next;
			ln1->next = l->next;
			l->next = ln1;
		}
		else
		{
			l2 = l2->next;
			ln2->next = l->next;
			l->next = ln2;
		}
		l = l->next;
	}
	if ( l1 == NULL )
	{
		l->next = l2;
	}
	else if ( l2 == NULL )
	{
		l->next = l1;
	}

	return r->next;
}