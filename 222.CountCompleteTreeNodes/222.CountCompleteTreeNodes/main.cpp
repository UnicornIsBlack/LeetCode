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
	int countNodes(TreeNode* root)
	{
		if ( !root )
			return 0;
		return 1 + countNodes(root->right) + countNodes(root->left);
	}
};

int main()
{
	return 0;
}