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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if ( !head )
			return head;
		bool isDup = false;
		ListNode* distinct;
		ListNode* duplicate = head;
		ListNode* node = duplicate->next;
		while ( node != NULL )
		{
			if ( node->val == duplicate->val )
				isDup = true;
			else
			{
				if ( isDup )
				{
					if ( duplicate == head )
						head = node;
					else
						distinct->next = node;
					ListNode* tmp;
					while ( duplicate != node )
					{
						tmp = duplicate;
						duplicate = duplicate->next;
						free(tmp);
					}
					isDup = false;
				}
				else
				{
					distinct = duplicate;
					duplicate = node;
				}
			}
			node = node->next;
		}
		if ( isDup )
		{
			if ( duplicate == head )
				head = NULL;
			else
				distinct->next = NULL;
			ListNode* tmp;
			while ( duplicate != NULL )
			{
				tmp = duplicate;
				duplicate = duplicate->next;
				free(tmp);
			}
		}
		return head;
	}
};

int main()
{
	return 0;
}