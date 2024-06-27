//
// Created by dingrui on 2024/6/27.
//
#include <stdlib.h>

#include "Stack.h"

Stack* StackInit()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->cap = 0;
	stack->sz = 0;
	return stack;
}

int StackEmpty(Stack* stack)
{
	return stack->sz == 0;
}

int StackPush(Stack* stack, int i)
{
	if (stack->sz == stack->cap)
	{
		// resize
		int preCap = stack->cap;
		int cap = (preCap == 0) ? 1 : preCap << 1;
		int* data = (int*)malloc(cap * sizeof(int));
		for (int i = 0; i < preCap; i++)
		{
			data[i] = stack->data[i];
		}
		stack->cap = cap;
		free(stack->data);
		stack->data = data;
	}
	stack->data[stack->sz++] = i;
}

int StackPop(Stack* stack)
{
	if (StackEmpty(stack)) return -1;
	int ret = stack->data[stack->sz - 1];
	stack->sz--;
	return ret;
}

void StackFree(Stack* stack)
{
	free(stack->data);
	free(stack);
}
