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
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
	public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		vector<int> nums;
		listToArray(head, nums);
		return sortedArrayToBST(nums);
	}

	void listToArray(ListNode* head, vector<int>& res)
	{
		ListNode* node = head;
		while ( node != NULL )
		{
			res.push_back(node->val);
			node = node->next;
		}
	}

	TreeNode* arrayToBST(vector<int>& nums, int low, int high)
	{
		if ( low > high )
		{
			return NULL;
		}
		else
		{
			int mid = (low + high) / 2;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = arrayToBST(nums, low, mid - 1);
			root->right = arrayToBST(nums, mid + 1, high);
			return root;
		}
	}

	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return arrayToBST(nums, 0, nums.size() - 1);
	}
};

int main()
{
	return 0;
}