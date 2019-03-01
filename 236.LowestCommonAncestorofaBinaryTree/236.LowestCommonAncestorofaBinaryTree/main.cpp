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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		TreeNode* res;
		vector<TreeNode*> pFather;
		vector<TreeNode*> qFather;
		dfs(root, p, pFather);
		dfs(root, q, qFather);
		int pLen = pFather.size();
		int qLen = qFather.size();
		for ( int i = pLen - 1, j = qLen - 1; i >= 0 && j >= 0; i--, j-- )
		{
			if ( pFather[i] != qFather[j] )
				break;
			res = pFather[i];
		}
		return res;
	}

	bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& father)
	{
		if ( !root )
			return false;
		if ( root == node )
		{
			father.push_back(root);
			return true;
		}
		if ( dfs(root->left, node, father) || dfs(root->right, node, father) )
		{
			father.push_back(root);
			return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}