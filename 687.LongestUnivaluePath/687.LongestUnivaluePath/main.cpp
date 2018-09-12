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
	int maxP;
	int maxPath(TreeNode* root)
	{
		if ( !root )
			return 0;
		int l = 0, r = 0;
		if ( !root->left || root->left->val != root->val )
			maxPath(root->left);
		else if ( root->left->val == root->val )
			l = maxPath(root->left) + 1;
		if ( !root->right || root->right->val != root->val )
			maxPath(root->right);
		else if ( root->right->val == root->val )
			r = maxPath(root->right) + 1;
		if ( l && r )
			maxP = max(maxP, l + r);
		maxP = max(maxP, max(l, r));
		return max(l, r);
	}
	int longestUnivaluePath(TreeNode* root)
	{
		maxP = 0;
		if ( !root )
			return 0;
		maxPath(root);
		return maxP;
	}
};

int main()
{
	return 0;
}