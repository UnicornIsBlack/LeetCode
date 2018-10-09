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
	bool leafSimilar(TreeNode* root1, TreeNode* root2)
	{
		vector<int> leafs1 = leafsArray(root1);
		vector<int> leafs2 = leafsArray(root2);
		if ( leafs1.size() != leafs2.size() )
			return false;
		bool flag = true;
		for ( int i = 0; i < leafs1.size(); i++ )
		{
			if ( leafs1[i] != leafs2[i] )
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	vector<int> leafsArray(TreeNode* root)
	{
		vector<int> leafs;
		treeTraversing(root, leafs);
		return leafs;
	}
	void treeTraversing(TreeNode* root,vector<int>& leafs)
	{
		if ( !root )
			return;
		if ( root->left == NULL && root->right == NULL )
			leafs.push_back(root->val);
		treeTraversing(root->left, leafs);
		treeTraversing(root->right, leafs);
	}
};

int main()
{
	return 0;
}