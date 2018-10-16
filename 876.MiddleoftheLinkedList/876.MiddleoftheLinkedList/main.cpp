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
	ListNode* middleNode(ListNode* head)
	{
		int count = 0;
		int mid = 0;
		ListNode* node = head;
		ListNode* middle = head;
		while ( node != NULL )
		{
			count++;
			if ( count / 2 > mid )
			{
				middle = middle->next;
				mid++;
			}
			node = node->next;
		}
		return middle;
	}
};

int main()
{
	return 0;
}