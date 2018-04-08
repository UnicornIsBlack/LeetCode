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

int subPathSum(struct TreeNode* root, int sum, int curSum)
{
	if ( root == NULL )
		return 0;
	int rInt = 0;
	int sInt = 0;
	if ( (root->val + curSum) == sum )
	{
		rInt = 1 + subPathSum(root->left, sum, curSum + root->val) + subPathSum(root->right, sum, curSum + root->val);
	}
	else
	{
		rInt = subPathSum(root->left, sum, curSum + root->val) + subPathSum(root->right, sum, curSum + root->val);
	}
	sInt = subPathSum(root->left, sum, 0) + subPathSum(root->right, sum, 0);

	return rInt + sInt;
}
int pathSum(struct TreeNode* root, int sum)
{
	return subPathSum(root, sum, 0);
}


int main()
{
	return 0;
}