//
// Created by dingrui on 2024/6/27.
//

#ifndef INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_
#define INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_

#include "Stack.h"

typedef struct Queue
{
	// 负责入队的元素
	Stack* s1;
	// 负责出队的元素
	Stack* s2;
} Queue;

Queue* QueueInit();
int QueueEnQueue(Queue* q, int elem);
int QueueDeQueue(Queue* q);

#endif //INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_
