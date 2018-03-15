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

void deleteNode(struct ListNode* node)
{
	struct ListNode* clone = node->next;
	node->val = clone->val;
	node->next = clone->next;
	free(clone);
}

int main()
{
	return 0;
}