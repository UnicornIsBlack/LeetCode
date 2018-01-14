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
/*本题困难之处在于两个指针长度不一定相等，所以不能进行同步遍历
**若存在相同的节点，则后续节点的长度相同，所以将长度较长的链表
**移动到和另一条相同长度的位置即可*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int aLen = 0;
	int bLen = 0;
	struct ListNode *aNode = headA;
	struct ListNode *bNode = headB;
	while ( aNode != NULL )
	{
		aNode = aNode->next;
		aLen++;
	}
	while ( bNode != NULL )
	{
		bNode = bNode->next;
		bLen++;
	}
	aNode = headA;
	bNode = headB;
	if ( aLen > bLen )
	{
		for ( int i = 0; i < aLen - bLen; i++ )
		{
			aNode = aNode->next;
		}
	}
	if ( bLen > aLen )
	{
		for ( int i = 0; i < bLen - aLen; i++ )
		{
			bNode = bNode->next;
		}
	}
	while ( bNode != NULL )
	{
		if ( aNode == bNode )
			return bNode;
		aNode = aNode->next;
		bNode = bNode->next;
	}
	return NULL;
}


int main()
{
	return 0;
}