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

bool isPalindrome(struct ListNode* head)
{
	int count = 0;
	struct ListNode* headReverse = NULL;
	struct ListNode* tmp = head;
	while ( tmp != NULL )
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = tmp->val;
		node->next = headReverse;
		headReverse = node;
		tmp = tmp->next;
		count++;
	}
	if ( count < 2 )
		return true;
	int i = 0;
	tmp = head;
	for ( i = 0; i < count / 2; i++ )
	{
		if ( tmp->val != headReverse->val )
			return false;
		tmp = tmp->next;
		headReverse = headReverse->next;
	}
	return true;
}

int main()
{
	return 0;
}