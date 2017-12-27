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
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};

int maxDepth(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;

	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;

	if ( left > right )
		return left;
	else
		return right;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	(*returnSize) = maxDepth(root);
	(*columnSizes) = (int*)malloc((*returnSize)*sizeof(int));
	int** returnArray = (int**)malloc((*returnSize)*sizeof(int*));

	if ( root == NULL )
		return returnArray;

	int size = 1;
	int arrayEnd = (*returnSize) - 1;
	

}


int main()
{
	return 0;
}