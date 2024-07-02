//
// Created by dingrui on 2024/6/28.
//

#include <stdlib.h>

#include "MyTree.h"

MyTreeNode* TreeNodeInit()
{
	MyTreeNode* tree = (MyTreeNode*)malloc(sizeof(MyTreeNode));
	return tree;
}
MyTreeNode* TreeNodeInitWithVal(int val)
{
	MyTreeNode* tree = TreeNodeInit();
	tree->val = val;
	return tree;
}
void dfsInorderSerial(MyTreeNode* t, int arr[], int* i)
{
	if (!t) return;
	dfsInorderSerial(t->left, arr, i);
	arr[(*i)++] = t->val;
	dfsInorderSerial(t->right, arr, i);
}
MyTreeNode* dfsInorderDeserial(int* arr, int s, int e)
{
	if (s > e) return NULL;
	if (s == e)
	{
		return TreeNodeInitWithVal(arr[s]);
	}
	else
	{
		int mid = s + ((e - s) >> 1);
		MyTreeNode* ans = TreeNodeInitWithVal(arr[mid]);
		ans->left = dfsInorderDeserial(arr, s, mid - 1);
		ans->right = dfsInorderDeserial(arr, mid + 1, e);
		return ans;
	}
}

int InorderSerial(MyTreeNode* t, int arr[])
{
	if (!t) return 0;
	int i = 0;
	dfsInorderSerial(t, arr, &i);
	return i;
}

MyTreeNode* InorderDeserial(int* arr, int sz)
{
	if (sz == 0) return NULL;
	return dfsInorderDeserial(arr, 0, sz - 1);
}