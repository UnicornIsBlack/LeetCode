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
struct TreeNode* arrayToBST(int* nums, int low, int high,struct TreeNode* root)
{
	if ( low > high )
	{
		free(root);
		return;
	}
	else
	{
		int mid = (low + high) / 2;
		root->val = nums[mid];
		struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		struct TreeNode* right = (struct TreeNode*)malloc(sizeof(struct TreeNode));

		arrayToBST(nums, low, mid - 1, left);
		arrayToBST(nums, mid + 1, high, right);
	}
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	int low = 0;
	int high = numsSize - 1;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	arrayToBST(nums,low,high,root);
	return root;
}

int main()
{
	return 0
}