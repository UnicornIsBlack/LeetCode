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


void invertSubTree(struct TreeNode* subRoot)
{
	if ( subRoot == NULL )
		return;

	struct TreeNode* tmp = subRoot->left;
	subRoot->left = subRoot->right;
	subRoot->right = tmp;
	invertSubTree(subRoot->left);
	invertSubTree(subRoot->right);
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	if ( root != NULL )
		invertSubTree(root);
	return root;
}


int main()
{
	return 0;
}