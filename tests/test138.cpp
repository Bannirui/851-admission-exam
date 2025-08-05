//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
typedef struct BTreeNode
{
    int               data;
    struct BTreeNode* left;
    struct BTreeNode* right;

    BTreeNode(int x)
    {
        this->data  = x;
        this->left  = nullptr;
        this->right = nullptr;
    }
} BTreeNode, *BTree;

/**
 * 从数组arr[lo...hi]创建二叉树
 */
BTree createBT(int arr[], int lo, int hi)
{
    BTree p;
    if (lo > hi) return nullptr;
    p        = new BTreeNode(arr[lo]);
    p->left  = createBT(arr, 2 * lo, hi);
    p->right = createBT(arr, 2 * lo + 1, hi);
    return p;
}

void print(BTree root)
{
    if (root == nullptr) return;
    std::cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main(int argc, const char** argv)
{
    int   arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BTree root  = createBT(arr, 1, 10);
    print(root);
    return 0;
}