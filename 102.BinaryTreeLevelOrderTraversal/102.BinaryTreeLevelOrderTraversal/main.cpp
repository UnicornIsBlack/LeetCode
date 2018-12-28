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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if ( !root )
			return res;
		dfs(root, res, 1);
		return res;
	}
	void dfs(TreeNode* root, vector<vector<int>>& res, int depth)
	{
		if ( !root )
			return;
		if ( res.size() < depth )
		{
			vector<int> leaf;
			res.push_back(leaf);
		}
		dfs(root->left, res, depth + 1);
		res[depth - 1].push_back(root->val);
		dfs(root->right, res, depth + 1);
	}


};

int main()
{
	return 0;
}