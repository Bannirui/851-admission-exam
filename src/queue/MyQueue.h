//
// Created by dingrui on 2024/6/27.
//

#pragma once

#include "MyStack.h"

typedef struct MyQueue
{
    // 负责入队的元素
    MyStack* s1;
    // 负责出队的元素
    MyStack* s2;
} MyQueue;

MyQueue* QueueInit();
int      EnQueue(MyQueue* q, int elem);
int      DeQueue(MyQueue* q);