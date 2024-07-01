//
// Created by dingrui on 2024/7/1.
//

#ifndef INC_851_ADMISSION_EXAM_SRC_INCLUDE_LISTNODE_H_
#define INC_851_ADMISSION_EXAM_SRC_INCLUDE_LISTNODE_H_

// 单链表
typedef struct MyListNode
{
	int val;
	struct MyListNode* next;
} MyListNode;

MyListNode* InitNode(int val);
MyListNode* InitListWithNext(MyListNode* next);
MyListNode* InitListFromArr(int* arr, int sz);
void ListPrint(MyListNode* head);
void FreeNode(MyListNode* node);
MyListNode* ListReverseBased1(MyListNode* head, int m, int n);
/**
 * based-0
 * 反转链表的指定部分[m...1]
 * @param head 链表
 * @param m 起始
 * @param n 结束
 */
MyListNode* ListReverseBased0(MyListNode* head, int m, int n);

#endif //INC_851_ADMISSION_EXAM_SRC_INCLUDE_LISTNODE_H_
