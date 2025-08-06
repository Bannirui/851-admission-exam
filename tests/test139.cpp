//
// Created by rui ding on 2025/8/5.
//

#include <cstdlib>
#include <iostream>
typedef struct BTreeNode
{
    int               data;
    struct BTreeNode* left;
    struct BTreeNode* right;
} BTreeNode, *BTree;

/**
 * 从数组创建二叉树
 * arr[1...n]
 */
BTree create(int arr[], int n)
{
    int i;
    // 二叉树结点数组
    BTree* pT;
    // 对应arr[1...n]这n个结点申请可容纳n个指针的内存空间
    // 结点数组预留1个0号位的槽 返回结果的时候从1开始
    pT = (BTree*)malloc((n + 1) * sizeof(BTreeNode));
    // 数组中的某个元素不等于0 则申请相应的结点空间
    for (i = 1; i <= n; i++)
    {
        if (arr[i] != 0)
        {
            pT[i]        = (BTree)malloc(sizeof(BTreeNode));
            pT[i]->data  = arr[i];
            pT[i]->left  = nullptr;
            pT[i]->right = nullptr;
        }
        else
        {
            pT[i] = nullptr;
        }
    }
    // 修改结点的指针域的内容 使父结点指向左右孩子结点
    for (i = 1; i <= n; i++)
    {
        if (pT[i] != nullptr)
        {
            pT[i]->left  = pT[i * 2];
            pT[i]->right = pT[i * 2 + 1];
        }
    }
    return pT[1];
}

void preOrderPrint(BTree root)
{
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main(int argc, const char** argv)
{
    int   arr[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BTree ret   = create(arr, 10);
    preOrderPrint(ret);
    return 0;
}