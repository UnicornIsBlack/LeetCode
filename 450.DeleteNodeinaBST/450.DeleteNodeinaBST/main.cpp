#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
	public:
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		if ( !root )
			return root;
		if ( root->val == key )
		{
			if ( root->left != NULL )
			{
				TreeNode* right = root->right;
				root = root->left;
				TreeNode* lright = root->right;
				if ( right != NULL )
				{
					dfs(right, lright);
					root->right = right;
				}
			}
			else
				root = root->right;
		}
		else if ( root->val > key )
		{
			TreeNode* left = deleteNode(root->left, key);
			root->left = left;
		}
		else if ( root->val < key )
		{
			TreeNode* right = deleteNode(root->right, key);
			root->right = right;
		}
		return root;
	}

	void dfs(TreeNode* root, TreeNode* node)
	{
		if ( root->left == NULL )
			root->left = node;
		else
			dfs(root->left, node);
	}
};

int main()
{
	return 0;
}