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
int minDepth(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;
	if ( root->left == NULL && root->right == NULL )
		return 1;
	
	if ( root->left == NULL )
		return minDepth(root->right) + 1;
	else if ( root->right == NULL )
		return minDepth(root->left) + 1;
	int leftTree = minDepth(root->left);
	int rightTree = minDepth(root->right);
	return leftTree < rightTree ? leftTree + 1 : rightTree + 1;
}

int main()
{
	return 0;
}