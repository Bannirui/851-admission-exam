//
// Created by rui ding on 2025/8/6.
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

// 求二叉树的深度 递归
int depth(BTree root)
{
    int ldepth, rdepth;
    if (root == nullptr) return 0;
    // 左子树的高度
    ldepth = depth(root->left);
    // 右子树的高度
    rdepth = depth(root->right);
    // 整个树的高度由最深的子树决定 再加个当前结点的这一层
    if (ldepth > rdepth)
        return ldepth + 1;
    else
        return rdepth + 1;
}

int main(int argc, const char** argv)
{
    BTree root = new BTreeNode(1);
    root->left = new BTreeNode(2);
    int ret    = depth(root);
    std::cout << "树高=" << ret << std::endl;
    return 0;
}