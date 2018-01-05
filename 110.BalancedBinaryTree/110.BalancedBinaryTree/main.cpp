#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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

int treeDeepth(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;
	int leftTree = treeDeepth(root->left);
	int rightTree = treeDeepth(root->right);

	if ( leftTree == -1 || rightTree == -1 )
		return -1;

	int sub = leftTree - rightTree;
	if ( sub == 0 || sub == 1 )
		return leftTree + 1;
	else if ( sub == -1 )
		return rightTree + 1;
	else
		return -1;
}

bool isBalanced(struct TreeNode* root)
{
	int flag = treeDeepth(root);
	if ( flag == -1 )
		return false;
	else
		return true;
}


int main()
{
	return 0;
}