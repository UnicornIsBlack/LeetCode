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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> res;
		if ( !root )
			return res;
		vector<int> result;
		dfs(root, res, result, sum);
		return res;
	}

	void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& result, int sum)
	{
		if ( !root )
			return;
		int s = sum - root->val;
		if ( s == 0 )
		{
			if ( root->left == NULL && root->right == NULL )
			{
				result.push_back(root->val);
				res.push_back(result);
				result.pop_back();
				return;
			}
		}
		result.push_back(root->val);
		dfs(root->left, res, result, s);
		dfs(root->right, res, result, s);
		result.pop_back();
	}
};

int main()
{
	return 0;
}