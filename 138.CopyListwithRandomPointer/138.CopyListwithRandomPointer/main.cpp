#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
	public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if ( !head )
			return NULL;
		unordered_map<RandomListNode*, RandomListNode*> mp;
		// ����һ���µ�����ͷ
		RandomListNode *new_head = new RandomListNode(head->label);
		// node1����ָ��ԭ����node2����ָ��������
		RandomListNode *node1 = head, *node2 = new_head;
		/**
		* ����ԭ����Ľṹ���ϴ����µĽڵ㣬��ά����nextָ�룬��node1��node2�Ķ�Ӧ��ϵ���浽hash_map�У�
		* �Ա�����ά��randomָ���ʱ�򣬿���ͨ��node1�ҵ���Ӧ��node2��
		*/
		while ( node1->next != NULL )
		{
			mp[node1] = node2;
			node1 = node1->next;
			node2->next = new RandomListNode(node1->label);
			node2 = node2->next;
		}
		// �����������β�͵Ķ�Ӧ��ϵҲ�����
		mp[node1] = node2;

		// ������ͷ��ʼ����randomָ��
		node1 = head;
		node2 = new_head;
		while ( node1->next != NULL )
		{
			node2->random = mp[node1->random];
			node1 = node1->next;
			node2 = node2->next;
		}
		// ��β�͵�randomָ��Ҳ�����
		node2->random = mp[node1->random];
		return new_head;
	}
};

int main()
{
	return 0;
}