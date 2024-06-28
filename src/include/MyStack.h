//
// Created by dingrui on 2024/6/27.
//

#ifndef INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_
#define INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_

typedef struct MyStack
{
	int cap;
	int sz;
	int* data;
} MyStack;

MyStack* StackInit();
int StackEmpty(MyStack* stack);
int StackPush(MyStack* stack, int i);
int StackPop(MyStack* stack);
void StackFree(MyStack* stack);

#endif //INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_
