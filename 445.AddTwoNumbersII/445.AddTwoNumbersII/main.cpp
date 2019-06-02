#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		stack<int> s1;
		stack<int> s2;
		int op = 0;
		ListNode* res = NULL;
		ListNode* node = l1;
		while ( node != NULL )
		{
			s1.push(node->val);
			node = node->next;
		}
		node = l2;
		while ( node != NULL )
		{
			s2.push(node->val);
			node = node->next;
		}

		while ( !s1.empty() && !s2.empty() )
		{
			int a = s1.top();
			s1.pop();
			int b = s2.top();
			s2.pop();
			int sum = a + b + op;
			op = sum / 10;
			sum %= 10;
			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
		}
		while ( !s1.empty() )
		{
			int a = s1.top();
			s1.pop();
			int sum = a + op;
			op = sum / 10;
			sum %= 10;
			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
		}
		while ( !s2.empty() )
		{
			int a = s2.top();
			s2.pop();
			int sum = a + op;
			op = sum / 10;
			sum %= 10;
			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
		}
		if ( op != 0 )
		{
			ListNode* node = new ListNode(op);
			node->next = res;
			res = node;
		}
		return res;
	}
};

int main()
{
	return 0;
}