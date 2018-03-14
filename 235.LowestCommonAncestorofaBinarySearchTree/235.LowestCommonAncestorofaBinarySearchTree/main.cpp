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
int int_max(int a, int b)
{
	return a > b ? a : b;
}
int int_min(int a, int b)
{
	return a < b ? a : b;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if ( root == p || root == q )
		return root;
	if ( root->val > int_max(p->val, q->val) )
	{
		root = lowestCommonAncestor(root->left, p, q);
	}
	else if ( root->val < int_min(p->val, q->val) )
	{
		root = lowestCommonAncestor(root->right, p, q);
	}
	return root;
}

int main()
{
	return 0; 
}