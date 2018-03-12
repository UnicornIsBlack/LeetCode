#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode
{
	int val;
	struct stackNode* ptr;
}SNode;

typedef struct
{
	SNode* top;
}MyStack;

typedef struct
{
	int maxSize;
	int len;
	MyStack* inStack;
	MyStack* outStack;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize)
{
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->maxSize = maxSize;
	queue->len = 0;
	queue->inStack = (MyStack*)malloc(sizeof(MyStack));
	queue->outStack = (MyStack*)malloc(sizeof(MyStack));
	queue->inStack->top = NULL;
	queue->outStack->top = NULL;
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	if ( obj->len == obj->maxSize )
		return;
	SNode* stackNode = (SNode*)malloc(sizeof(SNode));
	stackNode->val = x;
	stackNode->ptr = obj->inStack->top;
	obj->inStack->top = stackNode;
	obj->len++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	if ( obj->len == 0 )
		return;

	SNode* tmp = obj->inStack->top;
	while ( tmp->ptr != NULL )
	{
		obj->inStack->top = tmp->ptr;
		tmp->ptr = obj->outStack->top;
		obj->outStack->top = tmp;
		tmp = obj->inStack->top;
	}
	int val = tmp->val;
	obj->inStack->top = tmp->ptr;
	free(tmp);
	tmp = obj->outStack->top;
	while ( tmp != NULL )
	{
		obj->outStack->top = tmp->ptr;
		tmp->ptr = obj->inStack->top;
		obj->inStack->top = tmp;
		tmp = obj->outStack->top;
	}
	obj->len--;
	return val;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if ( obj->len == 0 )
		return;

	SNode* tmp = obj->inStack->top;
	while ( tmp->ptr != NULL )
	{
		obj->inStack->top = tmp->ptr;
		tmp->ptr = obj->outStack->top;
		obj->outStack->top = tmp;
		tmp = obj->inStack->top;
	}
	int val = tmp->val;
	tmp = obj->outStack->top;
	while ( tmp != NULL )
	{
		obj->outStack->top = tmp->ptr;
		tmp->ptr = obj->inStack->top;
		obj->inStack->top = tmp;
		tmp = obj->outStack->top;
	}
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	if ( obj->len == 0 )
		return true;
	else
		return false;
}

void myQueueFree(MyQueue* obj)
{
	free(obj->inStack);
	free(obj->outStack);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* struct MyQueue* obj = myQueueCreate(maxSize);
* myQueuePush(obj, x);
* int param_2 = myQueuePop(obj);
* int param_3 = myQueuePeek(obj);
* bool param_4 = myQueueEmpty(obj);
* myQueueFree(obj);
*/


int main()
{
	return 0;
}