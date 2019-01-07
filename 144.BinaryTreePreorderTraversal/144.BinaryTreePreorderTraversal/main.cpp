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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		dfs(root, result);
		return result;
	}

	void dfs(TreeNode* root, vector<int>& result)
	{
		if ( !root )
			return;
		result.push_back(root->val);
		dfs(root->left, result);
		dfs(root->right, result);
	}
};

int main()
{
	return 0;
}