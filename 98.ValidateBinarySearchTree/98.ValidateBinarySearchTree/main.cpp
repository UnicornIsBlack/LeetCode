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
	bool isValidBST(TreeNode* root)
	{
		if ( !root )
			return true;
		if ( !dfsLeft(root->left, root->val) || !dfsRight(root->right, root->val) )
			return false;
		return isValidBST(root->left) && isValidBST(root->right);
	}

	bool dfsLeft(TreeNode* root,int val)
	{
		if ( !root )
			return true;
		if ( root->val >= val )
			return false;
		return dfsLeft(root->left,val) && dfsLeft(root->right,val);
	}

	bool dfsRight(TreeNode* root, int val)
	{
		if ( !root )
			return true;
		if ( root->val <= val )
			return false;
		return dfsRight(root->left, val) && dfsRight(root->right, val);
	}
};

int main()
{
	return 0;
}