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
	void flatten(TreeNode* root)
	{
		if ( !root )
			return;
		dfs(root);
	}

	void dfs(TreeNode* root)
	{
		if ( root->left == NULL && root->right == NULL )
			return;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->right = NULL;
		if ( left != NULL )
		{
			dfs(left);
			root->right = left;
			root->left = NULL;
		}
		if ( right != NULL )
		{
			dfs(right);
			TreeNode* node = root;
			while ( node->right != NULL )
				node = node->right;
			node->right = right;
		}

	}
};


int main()
{
	return 0;
}