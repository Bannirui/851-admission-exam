//
// Created by rui ding on 2025/8/6.
//

#include <iostream>

#include <ostream>
// 求二叉树的深度 非递归中序遍历
// 算法思想
// 对二叉树进行遍历 遍历过程中依次记录各个结点所处的层次数以及当前已访问过的结点所处的最大层次数
// 每当访问到某个叶子结点时 将该叶子结点所处的层次数与最大层次数进行比较
// 若前者大于后者 则修改最大层次为叶子结点的层次数 否则不修改
// 遍历结束时 所记录的最大层次数即为该二叉树的深度
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

#define MAX_SIZE 50

// 非递归方式计算二叉树树高度 1-based
int depth(BTree root)
{
    BTree stack1[MAX_SIZE], p = root;
    int   stack2[MAX_SIZE];
    // 栈顶指针top -1表示栈是空的
    int curdepth, maxdepth = 0, top = -1;
    if (root != nullptr)
    {
        curdepth = 1;
        while (p != nullptr || top != -1)
        {
            // 先统计左子树 每入栈1个结点就树高+1
            while (p != nullptr)
            {
                // 入栈
                stack1[++top] = p;
                stack2[top]   = curdepth;
                p             = p->left;
                curdepth++;
            }
            // 左子树已经入完栈
            p        = stack1[top];
            curdepth = stack2[top--];
            if (p->left == nullptr && p->right == nullptr)
            {
                // 叶子结点 遇到叶子结点就是统计树高的时机
                if (curdepth > maxdepth) maxdepth = curdepth;
            }
            // 左子树已经看完了 开始看右子树
            p = p->right;
            curdepth++;
        }
    }
    return maxdepth;
}

int main(int argc, const char** argv)
{
    BTree root = new BTreeNode(1);
    root->left = new BTreeNode(2);
    int ret    = depth(root);
    std::cout << "树的深度=" << ret << std::endl;
    return 0;
}