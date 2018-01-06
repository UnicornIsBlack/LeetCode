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
bool hasPathSum(struct TreeNode* root, int sum)
{
	if ( root == NULL )
		return false;
	if ( root->left == NULL && root->right == NULL )
	{
		if ( sum == root->val )
			return true;
		else
			return false;
	}
	if ( root->left == NULL )
		return hasPathSum(root->right, sum - root->val);
	else if ( root->right == NULL )
		return hasPathSum(root->left, sum - root->val);
	bool left = hasPathSum(root->left, sum - root->val);
	bool right = hasPathSum(root->right, sum - root->val);
	return left || right;
}

bool hasPathSum1(struct TreeNode* root, int sum)
{
	if ( root == NULL ) return false;
	if ( root->left == NULL && root->right == NULL ) return sum == root->val;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
	return 0;
}