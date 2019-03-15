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
	int rob(TreeNode* root)
	{
		vector<int> money = { 0, 0 };
		dfs(root, money);
		return max(money[0], money[1]);
	}

	void dfs(TreeNode* root, vector<int>& money)
	{
		if ( !root )
			return;
		vector<int> left = { 0, 0 };
		vector<int> right = { 0, 0 };
		dfs(root->left, left);
		dfs(root->right, right);
		money[0] = root->val + left[1] + right[1];
		money[1] = max(left[0], left[1]) + max(right[0], right[1]);
	}
};

int main()
{
	return 0;
}