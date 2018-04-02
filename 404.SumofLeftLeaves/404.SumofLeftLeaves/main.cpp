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
int sumOfLeftLeaves(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;
	if ( root->left == NULL )
		return sumOfLeftLeaves(root->right);
	else
	{
		if ( root->left->left == NULL && root->left->right == NULL )
			return root->left->val + sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
}


int main()
{
	return 0;
}