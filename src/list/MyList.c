//
// Created by dingrui on 2024/7/1.
//
#include <stdio.h>
#include <stdlib.h>

#include "MyList.h"

#define MAX_SZ 1024

MyListNode* InitNode(int val)
{
	MyListNode* ans = (MyListNode*)malloc(sizeof(MyListNode));
	ans->val = val;
	return ans;
}
MyListNode* InitListWithNext(MyListNode* next)
{
	MyListNode* ans = (MyListNode*)malloc(sizeof(MyListNode));
	ans->next = next;
	return ans;
}
MyListNode* InitListFromArr(int* arr, int sz)
{
	if (sz == 0) return NULL;
	MyListNode* dummy = InitNode(-1);
	MyListNode* pre = dummy;
	for (int i = 0; i < sz; i++)
	{
		MyListNode* cur = InitNode(arr[i]);
		pre->next = cur;
		pre = pre->next;
	}
	MyListNode* ans = dummy->next;
	dummy->next = NULL;
	FreeNode(dummy);
	return ans;
}
void ListPrint(MyListNode* head)
{
	MyListNode* cur = head;
	int first = 1;
	if (head) printf("链表元素为 ");
	while (cur)
	{
		if (!first) printf("->");
		first = 0;
		printf("%d", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
void FreeNode(MyListNode* node)
{
	free(node);
}
MyListNode* ListReverseBased1(MyListNode* head, int m, int n)
{
	return ListReverseBased0(head, m - 1, n - 1);
}
MyListNode* ListReverseBased0(MyListNode* head, int m, int n)
{
	if (!head || m < 0 || m > n) return head;
	MyListNode* dummy = InitListWithNext(head);
	MyListNode* pre = dummy;
	// [0...m-1] [m...n] [n+1...]
	// pre指针要跳到m-1 总共m个元素
	for (int i = 0; i < m; i++)
	{
		pre = pre->next;
		if (!pre) goto fail;
	}
	// pre指向m-1
	MyListNode* preTail = pre;
	MyListNode* cur = pre->next;
	if (!cur) goto fail;
	// cur指向m [m...n]共计n-m+1个元素
	MyListNode* stack[MAX_SZ];
	int top = -1;
	for (int j = 0; j < n - m + 1; j++)
	{
		// 入栈
		stack[++top] = cur;
		cur = cur->next;
	}
	// cur指向n+1
	MyListNode* tailHead = cur;
	// 反转[m...n]
	while (top != -1)
	{
		preTail->next = stack[top--];
		preTail = preTail->next;
	}
	preTail->next = tailHead;
	MyListNode* ans = dummy->next;
	FreeNode(dummy);
	return ans;
fail:
	free(dummy);
	return head;
}
