#include <stdio.h>

#include "MyStack.h"
#include "MyTree.h"

// 数组的长度
#define MAX_SZ 1024

/**
 * 中序遍历二叉树{@param t} 将结果逆序存储在数组{@param a}中
 * 返回结果数组{@return}的长度
 */
int inorder(MyTreeNode* t, int* a)
{
	// 结果数组的长度
	int n = 0;
	// 用给定的阈值初始化数组长度 暂存二叉树节点
	MyTreeNode* arr[MAX_SZ];
	int top = -1;
	while (top != -1 || t != NULL)
	{
		while (t != NULL)
		{
			arr[++top] = t;
			t = t->right;
		}
		if (top != -1)
		{
			t = arr[top--];
			a[n++] = t->val;
			t = t->left;
		}
	}
	return n;
}

/**
 * 合并两个降序数组{@param a}和{@param b} 这两个数组长度分别为{@param n1}和{@param n2}
 * 合并完的数组{@param c}也是降序数组
 */
void merge(int* a, int* b, int* c, int n1, int n2)
{
	int n = 0;
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] > b[j]) c[n++] = a[i++];
		else c[n++] = b[j++];
	}
	while (i < n1) c[n++] = a[i++];
	while (j < n2) c[n++] = b[j++];
}

int main(int argc, char** argv)
{
	/**
	 * 设两棵二叉搜索树为t1和t2 分别进行逆中序遍历并将所有元素存储至两个数组中
	 * 此时两个数组分别对应二叉搜索树所有元素的降序排列
	 * 再将两个降序排列的数组合并为一个数组
	 */
	// 元数据构建两个二叉搜索树
	int srcA[] = { 1, 2, 3, 4, 5, 6, 7 };
	int srcB[] = { 8, 9, 10 };
	MyTreeNode* t1 = InorderDeserial(srcA, 7);
	MyTreeNode* t2 = InorderDeserial(srcB, 3);
	int a[MAX_SZ], b[MAX_SZ];
	int n1 = inorder(t1, a);
	int n2 = inorder(t2, b);
	int c[n1 + n2];
	merge(a, b, c, n1, n2);
	for (int i = 0; i < n1 + n2; i++)
	{
		printf("数组 脚标%d 元素%d\n", i, c[i]);
	}
	return 0;
}