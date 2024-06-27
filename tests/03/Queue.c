//
// Created by dingrui on 2024/6/27.
//

#include <stdlib.h>

#include "Queue.h"

Queue* QueueInit()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->s1 = StackInit();
	q->s2 = StackInit();
	return q;
}

int QueueEnQueue(Queue* q, int elem)
{
	StackPush(q->s1, elem);
}

int QueueDeQueue(Queue* q)
{
	if (StackEmpty(q->s1) && StackEmpty(q->s2)) return -1;
	if (StackEmpty(q->s2))
	{
		while (!StackEmpty(q->s1))
		{
			StackPush(q->s2, StackPop(q->s1));
		}
	}
	// 出队
	if (!StackEmpty(q->s2))
	{
		return StackPop(q->s2);
	}
	return -1;
}
