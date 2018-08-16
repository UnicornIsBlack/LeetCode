#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

char* connectStr(char* leftStr, char* rightStr)
{
	int leftLen = strlen(leftStr);
	int rightLen = strlen(rightStr);
	int strLen = leftLen + rightLen + 1;
	char* str = (char*)malloc(strLen*sizeof(char));
	str[strLen - 1] = '\0';
	int i = 0;
	for ( int j = 0; j < leftLen; j++, i++ )
	{

	}
}

char* tree2str(struct TreeNode* t)
{

}

int main()
{
	return 0;
}