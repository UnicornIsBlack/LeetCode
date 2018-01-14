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
/*��������֮����������ָ�볤�Ȳ�һ����ȣ����Բ��ܽ���ͬ������
**��������ͬ�Ľڵ㣬������ڵ�ĳ�����ͬ�����Խ����Ƚϳ�������
**�ƶ�������һ����ͬ���ȵ�λ�ü���*/
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