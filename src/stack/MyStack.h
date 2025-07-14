//
// Created by dingrui on 2024/6/27.
//

#pragma once

typedef struct MyStack
{
    int  cap;
    int  sz;
    int* data;
} MyStack;

MyStack* StackInit();
int      StackEmpty(MyStack* stack);
int      StackPush(MyStack* stack, int i);
int      StackPop(MyStack* stack);
void     StackFree(MyStack* stack);
