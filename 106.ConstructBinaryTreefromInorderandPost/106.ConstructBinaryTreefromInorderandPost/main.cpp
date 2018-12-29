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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		TreeNode* root = NULL;
		if ( postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size() )
			return root;
		root = dfs(postorder, inorder);
		return root;
	}

	TreeNode* dfs(vector<int>& postorder, vector<int>& inorder)
	{
		int end = postorder.size() - 1;
		TreeNode* root = new TreeNode(postorder[end]);
		int index = getIndex(inorder, postorder[end]);

		TreeNode* left = NULL;
		TreeNode* right = NULL;
		if ( index > 0 )
		{
			vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
			int len = leftInorder.size();
			vector<int> leftPostorder(postorder.begin(), postorder.begin() + len);
			left = dfs(leftPostorder, leftInorder);
		}
		if ( index < postorder.size() - 1 )
		{
			vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
			int len = rightInorder.size();
			vector<int> rightPostorder(postorder.begin() + postorder.size() - len - 1, postorder.end() - 1);
			right = dfs(rightPostorder, rightInorder);
		}
		root->left = left;
		root->right = right;
		return root;
	}

	int getIndex(vector<int>& nums, int target)
	{
		for ( int i = 0; i < nums.size(); i++ )
		{
			if ( nums[i] == target )
				return i;
		}
		return -1;
	}
};

int main()
{
	return 0;
}