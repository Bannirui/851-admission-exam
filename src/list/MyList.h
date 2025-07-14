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
/**
 * 将数组中数据作为链表节点数据.
 * @param arr 数组
 * @param sz 数组长度
 */
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

/**
 * [begin...end)链表排序 按照节点值升序.
 * @param begin 起始节点 inclusive
 * @param end 结束节点 exclusive
 */
void ListQuickSort(MyListNode* begin, MyListNode* end);

#endif //INC_851_ADMISSION_EXAM_SRC_INCLUDE_LISTNODE_H_
