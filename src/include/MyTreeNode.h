//
// Created by dingrui on 2024/6/28.
//

#ifndef INC_851_ADMISSION_EXAM_TESTS_04_TREENODE_H_
#define INC_851_ADMISSION_EXAM_TESTS_04_TREENODE_H_

typedef struct MyTreeNode
{
	int val;
	struct MyTreeNode* left;
	struct MyTreeNode* right;
} MyTreeNode;

MyTreeNode* TreeInit();
MyTreeNode* TreeInitVal(int val);
int InorderSerial(MyTreeNode* t, int arr[]);
MyTreeNode* InorderDeserial(int* arr, int sz);

#endif //INC_851_ADMISSION_EXAM_TESTS_04_TREENODE_H_
