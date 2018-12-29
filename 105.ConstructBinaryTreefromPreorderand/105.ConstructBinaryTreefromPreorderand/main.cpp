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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode* root = NULL;
		if ( preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size() )
			return root;
		root = dfs(preorder, inorder);
		return root;
	}
	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode* root = new TreeNode(preorder[0]);

		int index = getIndex(inorder, preorder[0]);
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		if ( index > 0 )
		{
			vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
			int len = leftInorder.size();
			vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + len + 1);
			left = dfs(leftPreorder, leftInorder);
		}
		if ( index < preorder.size() - 1 )
		{
			vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
			int len = rightInorder.size();
			vector<int> rightPreorder(preorder.begin() + preorder.size() - len, preorder.end());
			right = dfs(rightPreorder, rightInorder);
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
	vector<int> a = { 1, 2, 3, 4 };
	int index = 1;
	vector<int> b(a.begin(), a.begin() + index);
	cout << *a.begin() << endl;
	return 0;
}