#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode
{
	int val;
	struct QNode* next;
}QNode;
typedef struct
{
	QNode* front;
	QNode* end;
	int len;
}MyQueue;


typedef struct
{
	MyQueue* queue1;
	MyQueue* queue2;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize)
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	stack->queue1 = (MyQueue*)malloc(sizeof(MyQueue));
	stack->queue2 = (MyQueue*)malloc(sizeof(MyQueue));
	stack->queue1->front = NULL;
	stack->queue2->front = NULL;
	stack->queue1->end = NULL;
	stack->queue2->end = NULL;
	stack->queue1->len = 0;
	stack->queue2->len = 0;
	return stack;
}

void myQueuePush(MyQueue* q1, MyQueue* q2, int val)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->val = val;
	node->next = q2->front;
	q1->front = node;
	q1->len = q2->len + 1;
	if ( q2->len == 0 )
		q1->end = node;
	else
		q1->end = q2->end;
	q2->front = q2->end = NULL;
	q2->len = 0;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	if ( obj->queue1->len == 0 )
		myQueuePush(obj->queue1, obj->queue2, x);
	else
		myQueuePush(obj->queue2, obj->queue1, x);
}
int myQueuePop(MyQueue* q)
{
	if ( q->front == NULL )
		return;
	QNode* node = q->front;
	int val = node->val;
	q->front = node->next;
	q->end = q->front;
	q->len--;
	free(node);
	return val;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	if ( obj->queue1->len == 0 )
		return myQueuePop(obj->queue2);
	else
		return myQueuePop(obj->queue1);

}


int myQueueTop(MyQueue* q)
{
	if ( q->front == NULL )
		return;
	return q->front->val;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	if ( obj->queue1->len == 0 )
		return myQueueTop(obj->queue2);
	else
		return myQueueTop(obj->queue1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	if ( obj->queue1->len == 0 && obj->queue2->len == 0 )
		return true;
	else
		return false;
}

void myStackFree(MyStack* obj)
{
	while ( !myStackEmpty(obj) )
	{
		myStackPop(obj);
	}
	free(obj->queue1);
	free(obj->queue2);
}

/**
* Your MyStack struct will be instantiated and called as such:
* struct MyStack* obj = myStackCreate(maxSize);
* myStackPush(obj, x);
* int param_2 = myStackPop(obj);
* int param_3 = myStackTop(obj);
* bool param_4 = myStackEmpty(obj);
* myStackFree(obj);
*/

int main()
{
	return 0;
}