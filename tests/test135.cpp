//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
// 二叉树的中序遍历 非递归
// 算法思想
// 若p所指结点不为空 则将该结点的地址p入栈 然后再将p指向其左孩子结点
// 若p所指向的结点为空 则从堆栈中退出栈顶元素 并访问该结点 然后再将p指向该结点的右孩子结点
// 重复上述过程 直到p=NULL且堆栈为空 遍历结束
typedef struct BTreeNode
{
    int               data;
    struct BTreeNode* left;
    struct BTreeNode* right;

    BTreeNode(int x)
    {
        this->data  = x;
        this->left  = NULL;
        this->right = NULL;
    }
} BTreeNode, *BTree;

#define MAX_STACK 50

void visit(BTreeNode* node)
{
    std::cout << node->data << " ";
}

/**
 * 二叉树的中序遍历
 * @param root 二叉树
 */
void inorderTraverse(BTree root)
{
    // 栈
    BTree stack[MAX_STACK], p = root;
    // 栈顶指针
    int top = -1;
    // 退出条件是树遍历结束 栈为空
    while (p || top != -1)
    {
        while (p)
        {
            stack[++top] = p;
            p            = p->left;
        }
        // 左->根->右
        p = stack[top--];
        visit(p);
        p = p->right;
    }
}

int main(int argc, char** argv)
{
    BTree root       = new BTreeNode(1);
    root->left       = new BTreeNode(2);
    root->left->left = new BTreeNode(4);
    root->right      = new BTreeNode(3);
    inorderTraverse(root);
    return 0;
}