#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int *data;
	int *min;
	int minTop;
	int dataTop;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize)
{
	MinStack *minStack = (MinStack*)malloc(sizeof(MinStack));
	minStack->minTop = -1;
	minStack->dataTop = -1;
	minStack->data = (int*)malloc(maxSize*sizeof(int));
	minStack->min = (int*)malloc(maxSize*sizeof(int));
	return minStack;
}

void minStackPush(MinStack* obj, int x)
{
	obj->dataTop++;
	obj->data[obj->dataTop] = x;
	if ( obj->minTop == -1 || x <= obj->min[obj->minTop] )
	{
		obj->minTop++;
		obj->min[obj->minTop] = x;
	}
}

void minStackPop(MinStack* obj)
{
	if ( obj->dataTop >= 0 )
	{
		int data = obj->data[obj->dataTop];
		obj->dataTop--;
		if ( obj->min[obj->minTop] == data )
		{
			obj->minTop--;
		}
	}
}

int minStackTop(MinStack* obj)
{
	return obj->data[obj->dataTop];
}

int minStackGetMin(MinStack* obj)
{
	return obj->min[obj->minTop];
}

void minStackFree(MinStack* obj)
{
	free(obj);
}

/**
* Your MinStack struct will be instantiated and called as such:
* struct MinStack* obj = minStackCreate(maxSize);
* minStackPush(obj, x);
* minStackPop(obj);
* int param_3 = minStackTop(obj);
* int param_4 = minStackGetMin(obj);
* minStackFree(obj);
*/

int main()
{
	return 0;
}