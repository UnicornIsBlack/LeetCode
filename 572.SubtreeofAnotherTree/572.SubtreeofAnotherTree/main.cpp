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

bool isSame(struct TreeNode* s, struct TreeNode* t)
{
	if ( s == NULL && t == NULL )
		return true;
	else if ( s != NULL && t != NULL )
	{
		if ( s->val == t->val )
		{
			return isSame(s->left, t->left) && isSame(s->right, t->right);
		}
		else
			return false;
	}
	else
		return false;

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if ( s == NULL )
		return false;
	if ( isSame(s, t) )
		return true;
	else
		return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main()
{
	return 0;
}