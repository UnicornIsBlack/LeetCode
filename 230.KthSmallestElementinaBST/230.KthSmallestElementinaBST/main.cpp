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
	int kthSmallest(TreeNode* root, int k)
	{
		vector<int> nums;
		dfs(root, nums);
		return nums[k - 1];
	}
	void dfs(TreeNode* root, vector<int>& nums)
	{
		if ( !root )
			return;
		dfs(root->left, nums);
		nums.push_back(root->val);
		dfs(root->right, nums);
	}
};

int main()
{
	return 0;
}