//
// Created by rui ding on 2025/8/4.
//

#include <iostream>
// 统计二叉树中有左孩子结点个数并输出这些结点
typedef int Type;
typedef struct BiNode
{
    Type           data;
    struct BiNode* left;
    struct BiNode* right;
} BiNode;

int count(BiNode* root)
{
    if (!root) return 0;
    int l = count(root->left);
    int r = count(root->right);
    int c = l + r;
    if (root->left)
    {
        c++;
        std::cout << root->data << std::endl;
    }
    return c;
}

int main(int argc, const char** argv)
{
    BiNode n3;
    n3.data  = 3;
    n3.left  = NULL;
    n3.right = NULL;
    BiNode n2;
    n2.data  = 2;
    n2.left  = nullptr;
    n2.right = nullptr;
    BiNode n1;
    n1.data  = 1;
    n1.left  = &n2;
    n1.right = &n3;

    count(&n1);
    return 0;
}