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
	if ( (root->val + curSum) == sum )
	{
		rInt++;
	}
	rInt += subPathSum(root->left, sum, curSum + root->val) + subPathSum(root->right, sum, curSum + root->val);

	return rInt;
}
int pathSum(struct TreeNode* root, int sum)
{
	if ( root == NULL )
		return 0;
	return subPathSum(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
}


int main()
{
	return 0;
}