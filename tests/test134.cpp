//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
// 二叉树的先序遍历 非递归
// 算法思想
// 若p所指结点不为空 则访问该结点 然后将该结点的地址入栈 然后再将p指向其左孩子结点
// 若p所指向的结点为空 则从堆栈中退出栈顶元素 将p指向其右孩子结点
// 重复上述过程直到p=NULL且堆栈为空 遍历结束
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

#define MAX_STACK 50

void visit(BTreeNode* node)
{
    // 访问当前结点
    std::cout << node->data << " ";
}

/**
 * 二叉树先序遍历
 * 根->左->右
 * @param root 二叉树
 */
void preOrderTraverse(BTree root)
{
    BTree stack[MAX_STACK], p = root;
    // 栈顶指针 -1标识栈空
    int top = -1;
    while (p != nullptr || top != -1)
    {
        while (p != nullptr)
        {
            // 访问当前结点
            visit(p);
            // 入栈后继续访问左孩子
            stack[++top] = p;
            p            = p->left;
        }
        // 左孩子遍历完 出栈遍历右孩子
        p = stack[top--];
        p = p->right;
    }
}

int main(int argc, const char** argv)
{
    BTree root        = new BTreeNode(1);
    root->left        = new BTreeNode(2);
    root->right       = new BTreeNode(3);
    root->left->left  = new BTreeNode(4);
    root->left->right = new BTreeNode(5);
    root->right->left = new BTreeNode(6);

    preOrderTraverse(root);
    return 0;
}