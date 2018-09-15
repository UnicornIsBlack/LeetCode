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
	TreeNode* searchBST(TreeNode* root, int val)
	{
		if ( !root )
			return NULL;
		if ( root->val == val )
			return root;
		TreeNode* left = searchBST(root->left, val);
		TreeNode* right = searchBST(root->right, val);
		if ( left != NULL )
			return left;
		if ( right != NULL )
			return right;
		return NULL;
	}
};


int main()
{
	return 0;
}