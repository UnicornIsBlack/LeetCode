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
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head)
	{
		count = 0;
		ListNode* node = head;
		while ( node != NULL )
		{
			count++;
			node = node->next;
		}
		this->head = head;
	}

	/** Returns a random node's value. */
	int getRandom()
	{
		int n = rand() % count;
		ListNode* node = head;
		for ( int i = 0; i != n; i++ )
			node = node->next;
		return node->val;
	}
	private:
	int count;
	ListNode* head;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

int main()
{
	return 0;
}