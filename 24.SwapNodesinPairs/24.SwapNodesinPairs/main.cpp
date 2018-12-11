#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

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
	ListNode* swapPairs(ListNode* head)
	{
		stack<ListNode*> listStack;
		ListNode* result = new ListNode(1);
		ListNode* end = result;
		ListNode* node = head;
		while ( node != NULL )
		{
			if ( listStack.size() == 2 )
			{
				ListNode* first = listStack.top();
				listStack.pop();
				ListNode* second = listStack.top();
				listStack.pop();

				first->next = end->next;
				end->next = first;
				second->next = first->next;
				first->next = second;
				end = second;
			}
			listStack.push(node);
			node = node->next;
		}
		while ( !listStack.empty() )
		{
			ListNode* first = listStack.top();
			listStack.pop();
			first->next = end->next;
			end->next = first;
			end = first;
		}
		return result->next;

	}
};

int main()
{
	return 0;
}