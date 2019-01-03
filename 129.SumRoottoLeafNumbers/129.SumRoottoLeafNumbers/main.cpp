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
	int sumNumbers(TreeNode* root)
	{
		if ( !root )
			return 0;
		vector<int> leafs;
		dfs(leafs, root, 0);
		int sum = 0;
		for ( int i = 0; i < leafs.size(); i++ )
			sum += leafs[i];
		return sum;
	}

	void dfs(vector<int>& leafs, TreeNode* root, int num)
	{
		if ( !root )
			return;
		num = num * 10 + root->val;
		if ( root->left == NULL && root->right == NULL )
			leafs.push_back(num);
		dfs(leafs, root->left, num);
		dfs(leafs, root->right, num);
	}
};

int main()
{
	return 0;
}