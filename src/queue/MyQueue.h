//
// Created by dingrui on 2024/6/27.
//

#ifndef INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_
#define INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_

#include "MyStack.h"

typedef struct MyQueue
{
	// 负责入队的元素
	MyStack* s1;
	// 负责出队的元素
	MyStack* s2;
} MyQueue;

MyQueue* QueueInit();
int EnQueue(MyQueue* q, int elem);
int DeQueue(MyQueue* q);

#endif //INC_861_ADMISSION_EXAM_TESTS_03_QUEUE_H_
