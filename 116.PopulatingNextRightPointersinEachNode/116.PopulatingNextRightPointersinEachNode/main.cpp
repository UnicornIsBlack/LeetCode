#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
	public:
	void connect(TreeLinkNode *root)
	{
		vector<TreeLinkNode*> ends;
		dfs(ends, root, 1);
	}

	void dfs(vector<TreeLinkNode*>& ends, TreeLinkNode *root, int depth)
	{
		if ( !root )
			return;
		if ( ends.size() < depth )
			ends.push_back(root);
		else
		{
			ends[depth - 1]->next = root;
			ends[depth - 1] = root;
		}
		dfs(ends, root->left, depth + 1);
		dfs(ends, root->right, depth + 1);
	}
};

int main()
{
	return 0;
}