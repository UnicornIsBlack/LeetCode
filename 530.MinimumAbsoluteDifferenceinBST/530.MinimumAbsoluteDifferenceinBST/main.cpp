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


int getMinSubTree(struct TreeNode* root, int &first, int &second)
{
	if ( root == NULL )
		return;
	int sub = 0;
	int min = -1;
	if ( root->left == NULL )
	{
		if ( first < 0 )
		{
			first = root->val;
			if ( root->right == NULL )
				return -1;
			else
			{
				min = getMinSubTree(root->right, first, second);
				return;
			}
		}
		if ( second < 0 )
		{
			second = root->val;
			if ( root->right == NULL )
				return second - first;
			else
			{
				min = getMinSubTree(root->right, first, second);
				return;
			}
		}
		first = second;
		second = root->val;
		sub = second - first;
		if ( root->right == NULL )
			return sub;
		else
		{
			min = getMinSubTree(root->right, first, second);

		}
	}
	else
	{
		min = getMinSubTree(root->left, first, second);
		if ( second < 0 )
		{
			second = root->val;
			return second - first;
		}

	}
}
int getMinimumDifference(struct TreeNode* root)
{
	if ( root == NULL )
		return;
	int first = -1;
	int second = -1;
	int min = -1;
	min = getMinSubTree(root, first, second, min);
}

int main()
{
	return 0;
}