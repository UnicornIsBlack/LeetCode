#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSame(struct TreeNode* left, struct TreeNode* right)
{
	if ( left == NULL || right == NULL )
	{
		return left == right;
	}

	if ( left->val != right->val )
	{
		return false;
	}

	return isSame(left->left, right->right) && isSame(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if ( root == NULL )
		return true;
	return isSame(root->left, root->right);
}