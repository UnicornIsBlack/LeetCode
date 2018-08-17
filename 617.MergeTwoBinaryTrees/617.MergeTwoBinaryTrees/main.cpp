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

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
	if ( t1 == NULL && t2 == NULL )
		return NULL;
	else if ( t1 != NULL && t2 == NULL )
		return t1;
	else if ( t1 == NULL && t2 != NULL )
		return t2;
	struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = t1->val + t2->val;
	t->left = mergeTrees(t1->left, t2->left);
	t->right = mergeTrees(t1->right, t2->right);
	return t;
}

int main()
{
	return 0;
}