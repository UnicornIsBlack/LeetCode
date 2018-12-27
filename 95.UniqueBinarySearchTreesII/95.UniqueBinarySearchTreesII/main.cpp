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
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode*> roots;
		if ( n == 0 )
			return roots;
		dfs(1, n, roots);
		return roots;
	}

	void dfs(int start, int end,vector<TreeNode*>& roots)
	{
		if ( start > end )
		{
			roots.push_back(NULL);
			return;
		}
		for ( int i = start; i <= end; i++ )
		{
			vector<TreeNode*> lefts;
			dfs(start, i - 1,lefts);
			vector<TreeNode*> rights;
			dfs(i + 1, end,rights);
			for ( int m = 0; m < lefts.size(); m++ )
			{
				for ( int n = 0; n < rights.size(); n++ )
				{
					TreeNode* r = new TreeNode(i);
					r->left = lefts[m];
					r->right = rights[n];
					roots.push_back(r);
				}
			}
		}
	}
};

int main()
{
	return 0;
}