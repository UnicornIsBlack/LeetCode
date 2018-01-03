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
	(*columnSizes)[2] = 0;
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
	initQueue(queue, root);
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
		(*columnSizes)[num] = q->n;
		q = q->next;
		free(queue);
		queue = q;
		num--;
	}
	return returnArray;

}

void createTree(struct TreeNode* root, struct TreeNode* left, struct TreeNode* right)
{
	root->left = left;
	root->right = right;
}

void createBinaryTree(struct TreeNode* root)
{	
	struct TreeNode *rtLeft, *rtRight, *rLeft, *rRight;
	rtLeft = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	rtRight = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	rLeft = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	rRight = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = 3;
	rtLeft->val = 9;
	rtRight->val = 20;
	rLeft->val = 15;
	rRight->val = 7;
	createTree(root, rtLeft, rtRight);
	createTree(rtLeft, NULL, NULL);
	createTree(rtRight, rLeft, rRight);
	createTree(rLeft, NULL, NULL);
	createTree(rRight, NULL, NULL);

}


int main()
{
	struct TreeNode* root;
	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	createBinaryTree(root);
	int* columnSizes = { 0 };
	int returnSize = 0;
	int** returnArray = { 0 };
	returnArray = levelOrderBottom(root, &columnSizes, &returnSize);
	for ( int i = 0; i < returnSize; i++ )
	{
		int n = columnSizes[i];
		for ( int j = 0; j < n; j++ )
		{
			printf("%d ", returnArray[i][j]);
		}
		printf("\n");
	}
	return 0;
}