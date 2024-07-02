#include <stdio.h>

#include "MyTree.h"

/**
 * 给定一棵二叉搜索树 查找节点p和节点q的最小公共祖先.
 * @param root 二叉搜索树
 * @param p 节点
 * @param q 节点
 */
MyTreeNode* lowestCommonAncestor(MyTreeNode* root, MyTreeNode* p, MyTreeNode* q)
{
	// corner
	if (!root) return root;
	if (!p) return q;
	if (!q) return p;
	// 两个非空节点
	if ((p->val < root->val) && (root->val < q->val))return root;
	// 两个节点都在树的同一侧
	if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
	else return lowestCommonAncestor(root->right, p, q);
}

int main(int argc, char** argv)
{
	int i = 1;
	int sz;
	sscanf(argv[i++], "%d", &sz);
	if (sz <= 0)
	{
		printf("sz=%d不符合数组长度要求\n", sz);
		if (sz <= 0)
		{
			printf("sz=%d不符合数组长度要求\n", sz);
		}
	}
	int arr[sz];
	for (int j = 0; j < sz; j++) sscanf(argv[i++], "%d", &arr[j]);
	// 二叉搜索树
	MyTreeNode* root = InorderDeserial(arr, sz);
	// 两个目标节点
	int pVal, qVal;
	sscanf(argv[i++], "%d", &pVal);
	sscanf(argv[i], "%d", &qVal);
	printf("节点 p=%d q=%d\n", pVal, qVal);
	MyTreeNode* p = TreeNodeInitWithVal(pVal);
	MyTreeNode* q = TreeNodeInitWithVal(qVal);
	// 搜索二叉树中查找公共祖先节点
	MyTreeNode* ans = lowestCommonAncestor(root, p, q);
	if (!ans) printf("公共祖先节点是空");
	else printf("公共祖先节点是%d\n", ans->val);
	return 0;
}