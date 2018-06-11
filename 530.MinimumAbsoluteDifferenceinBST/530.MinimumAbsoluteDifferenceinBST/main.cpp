#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct ListNode
{
	int val;
	struct ListNode *next;
}*List;

List head = (List)malloc(sizeof(struct ListNode));
List end = head;

void middleSearch(struct TreeNode* root)
{
	if ( root == NULL )
		return;
	middleSearch(root->left);
	List node = (List)malloc(sizeof(struct ListNode));
	node->val = root->val;
	node->next = end->next;
	end->next = node;
	end = node;
	middleSearch(root->right);
}

int getMinimumDifference(struct TreeNode* root)
{
	end->next = NULL;
	middleSearch(root);
	int min = -1;
	List node = head;
	node = node->next;
	int first = node->val;
	node = node->next;
	int second = node->val;
	min = second - first;
	node = node->next;
	int mid = 0;
	while ( node != NULL )
	{
		first = second;
		second = node->val;
		mid = second - first;
		if ( mid < min )
			min = mid;
		node = node->next;
	}
	return min;
}

int main()
{
	return 0;
}