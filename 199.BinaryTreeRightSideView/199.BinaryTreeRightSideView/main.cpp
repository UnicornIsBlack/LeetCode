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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> res;
		dfsRight(root, res, 1);
		return res;
	}

	void dfsRight(TreeNode* root, vector<int>& res, int depth)
	{
		if ( !root )
			return;
		res.push_back(root->val);
		dfsRight(root->right, res, depth + 1);
		dfsLeft(root->left, res, depth + 1);
	}

	void dfsLeft(TreeNode* root, vector<int>& res, int depth)
	{
		if ( !root )
			return;
		if ( res.size() < depth )
			dfsRight(root, res, depth);
		else
		{
			dfsLeft(root->right, res, depth + 1);
			dfsLeft(root->left, res, depth + 1);
		}
	}
};

int main()
{
	return 0;
}
