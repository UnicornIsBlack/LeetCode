#include <iostream>
#include <vector>
#include <queue>

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
	vector<double> averageOfLevels(TreeNode* root)
	{
		if ( !root )
			return{};
		vector<double> res;
		queue<TreeNode*> q;
		q.push(root);

		while ( !q.empty() )
		{
			int n = q.size();
			double sum = 0;
			for ( int i = 0; i < n; i++ )
			{
				TreeNode* node = q.front();
				q.pop();
				sum += node->val;
				if ( node->left )
					q.push(node->left);
				if ( node->right )
					q.push(node->right);
			}
			res.push_back(sum / n);
		}
		return res;
	}
};