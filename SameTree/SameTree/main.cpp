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
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if ( p == NULL || q == NULL )
		return p == q;

	if ( p->val != q->val )
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
	return 0;
}