//
// Created by dingrui on 2024/6/27.
//

#ifndef INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_
#define INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_

typedef struct Stack
{
	int cap;
	int sz;
	int* data;
} Stack;

Stack* StackInit();
int StackEmpty(Stack* stack);
int StackPush(Stack* stack, int i);
int StackPop(Stack* stack);
void StackFree(Stack* stack);

#endif //INC_861_ADMISSION_EXAM_TESTS_03_STACK_H_
