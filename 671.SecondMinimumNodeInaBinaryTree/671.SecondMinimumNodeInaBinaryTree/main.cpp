#include <iostream>
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
	int findSecondMinimumValue(TreeNode* root)
	{
		if ( !root )
			return -1;
		return findSecondMinimum(root->val, root);
	}

	int findSecondMinimum(int rootNum, TreeNode* root)
	{
		if ( root->left == NULL && root->right == NULL )
		{
			if ( root->val == rootNum )
				return -1;
			else
				return root->val;
		}
		int leftMin = findSecondMinimum(rootNum, root->left);
		int rightMin = findSecondMinimum(rootNum, root->right);
		if ( leftMin == -1 && rightMin == -1 )
			return -1;
		if ( leftMin == -1 )
			return rightMin;
		if ( rightMin == -1 )
			return leftMin;
		return min(leftMin, rightMin);
	}

};
int main()
{
	return 0;
}