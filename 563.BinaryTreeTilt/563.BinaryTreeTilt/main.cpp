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

int tilt = 0;

int absolute(int val)
{
	return val >= 0 ? val : -val;
}
int treeTilt(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;
	int left = treeTilt(root->left);
	int right = treeTilt(root->right);
	tilt += absolute(left - right);
	return left + right;
}
int findTilt(struct TreeNode* root)
{
	tilt = 0;
	treeTilt(root);
	return tilt;
}

int main()
{
	return 0;
}