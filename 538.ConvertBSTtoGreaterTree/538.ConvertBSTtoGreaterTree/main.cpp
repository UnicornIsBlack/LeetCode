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

void greaterTree(struct TreeNode* root,int* plus)
{
	if ( root == NULL )
		return ;
	greaterTree(root->right,plus);
	root->val += (*plus);
	(*plus) = root->val;
	greaterTree(root->left,plus);
}

struct TreeNode* convertBST(struct TreeNode* root)
{
	int k = 0;
	int* plus = &k;
	greaterTree(root, plus);
	return root;
}

int main()
{
	return 0;
}