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
	TreeNode* increasingBST(TreeNode* root)
	{
		if ( !root )
			return root;
		vector<int> nodes;
		queryTree(root, nodes);
		TreeNode* resultTree = new TreeNode(nodes[0]);
		TreeNode* parent = resultTree;
		for ( int i = 1; i < nodes.size(); i++ )
		{
			TreeNode* node = new TreeNode(nodes[i]);
			parent->right = node;
			parent = node;
		}
		return resultTree;
	}
	void queryTree(TreeNode* root, vector<int>& nodes)
	{
		if ( !root )
			return;
		queryTree(root->left, nodes);
		nodes.push_back(root->val);
		queryTree(root->right, nodes);
	}
};

int main()
{
	return 0;
}