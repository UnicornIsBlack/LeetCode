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
	int minDiffInBST(TreeNode* root)
	{
		minNum = INT_MAX;
		prev = 0;
		flag = false;
		findMin(root);
		return minNum;
	}
	void findMin(TreeNode* root)
	{
		if ( !root )
			return;
		findMin(root->left);
		if ( flag )
		{
			minNum = min(minNum, root->val - prev);
		}
		flag = true;
		prev = root->val;
		findMin(root->right);
	}
	private:
	int minNum = INT_MAX;
	int prev = 0;
	bool flag = false;
};

int main()
{
	return 0;
}