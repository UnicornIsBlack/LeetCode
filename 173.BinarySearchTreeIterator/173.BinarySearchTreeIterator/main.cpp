#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
class BSTIterator
{
	private:
	stack<TreeNode*> it;
	public:
	BSTIterator(TreeNode* root)
	{
		TreeNode* node = root;
		while ( node != NULL )
		{
			it.push(node);
			node = node->left;
		}
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode* node = it.top();
		it.pop();
		if ( node->right != NULL )
		{
			TreeNode* root = node->right;
			while ( root != NULL )
			{
				it.push(root);
				root = root->left;
			}
		}
		return node->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !it.empty();
	}
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

int main()
{
	return 0;
}