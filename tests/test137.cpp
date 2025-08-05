//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
// 二叉树的按层次遍历
// 算法思想
// 设置一个队列 首先将根结点入队列 然后依次从队列中退出一个元素 每退出一个元素 先访问该元素所指的结点
// 然后依次将该结点的左孩子结点和右孩子结点入队列
// 如此重复直到队列为空
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

    void Print() { std::cout << this->data << " "; }
} BTreeNode, *BTree;

#define MAX_QUEUE 50

void layeredOrderTraverse(BTree root)
{
    BTree queue[MAX_QUEUE], p;
    int   front, rear;
    if (root != nullptr)
    {
        queue[0] = root;
        front    = -1;
        rear     = 0;
        // 出队直到队列空
        while (front < rear)
        {
            // 访问当前结点
            p = queue[++front];
            p->Print();
            if (p->left)
            {
                // 左结点入队
                queue[++rear] = p->left;
            }
            if (p->right)
            {
                // 右结点入队
                queue[++rear] = p->right;
            }
        }
    }
}

int main(int argc, const char** argv)
{
    BTree root  = new BTreeNode(1);
    root->left  = new BTreeNode(2);
    root->right = new BTreeNode(3);
    layeredOrderTraverse(root);
    return 0;
}