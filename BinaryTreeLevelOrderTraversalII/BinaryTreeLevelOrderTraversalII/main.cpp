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
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};

struct QueueNode
{
	struct QueueNode* next;
	struct TreeNode* tNode;
};

struct Queue
{
	int n;
	struct Queue* next;
	struct QueueNode* fLastNode;
};

int maxDepth(struct TreeNode* root)
{
	if ( root == NULL )
		return 0;

	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;

	if ( left > right )
		return left;
	else
		return right;
}

void initQueue(struct Queue* queue, struct TreeNode* root)
{
	if ( root == NULL )
		return;
	queue->n++;
	struct QueueNode* qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	qNode->next = queue->fLastNode->next;
	qNode->tNode = root;
	queue->fLastNode->next = qNode;

	initQueue(queue->next, root->right);
	initQueue(queue->next, root->left);
	return;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	(*returnSize) = maxDepth(root);
	(*columnSizes) = (int*)malloc((*returnSize)*sizeof(int));
	int** returnArray = (int**)malloc((*returnSize)*sizeof(int*));

	if ( root == NULL )
		return returnArray;
	
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->n = 0;
	queue->fLastNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	queue->fLastNode->next = NULL;
	queue->fLastNode->tNode = NULL;
	struct Queue* q = queue;
	q->next = NULL;

	for ( int i = 1; i < (*returnSize); i++ )
	{
		struct Queue* p = (struct Queue*)malloc(sizeof(struct Queue));
		p->n = 0;
		p->fLastNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
		p->fLastNode->next = NULL;
		p->fLastNode->tNode = NULL;
		p->next = NULL;
		q->next = p;
		q = p;
	}

	int num = (*returnSize) - 1;
	q = queue;
	while ( q != NULL )
	{
		returnArray[num] = (int*)malloc((q->n)*sizeof(int));
		struct QueueNode* qNode = q->fLastNode->next;
		struct QueueNode* nowNode = qNode;
		for ( int j = 0; j < q->n; j++ )
		{
			returnArray[num][j] = qNode->tNode->val;
			nowNode = qNode;
			qNode = nowNode->next;
			free(nowNode);
		}
		q = q->next;
		free(queue);
		queue = q;
	}
	return returnArray;

}


int main()
{
	return 0;
}