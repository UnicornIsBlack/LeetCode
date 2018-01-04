#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode* arrayToBST(int* nums, int low, int high)
{
	if ( low > high )
	{
		return NULL;
	}
	else
	{
		struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		int mid = (low + high) / 2;
		root->val = nums[mid];

		root->left = arrayToBST(nums, low, mid - 1);
		root->right = arrayToBST(nums, mid + 1, high);
		return root;
	}
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	return arrayToBST(nums, 0, numsSize - 1);
}

int main()
{
	return 0;
}