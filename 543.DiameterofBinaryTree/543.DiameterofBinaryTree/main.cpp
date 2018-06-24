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

int max = 0;

int maxNum(int a, int b)
{
	return a > b ? a : b;
}
int maxDepth(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	max = maxNum(max, left + right);
	return 1 + maxNum(left, right);

}
int diameterOfBinaryTree(struct TreeNode* root)
{
	maxDepth(root);
	return max;
}

int main()
{
	return 0;
}