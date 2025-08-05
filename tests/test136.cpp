//
// Created by rui ding on 2025/8/5.
//

// 二叉树的后序遍历 非递归
// 算法思想
// 当p指向某一结点时 不能马上对它进行访问 而要先访问它的左子树 因而要将此结点的地址入栈
// 当其左子树访问完毕后 再次搜索到该结点时 还不能对它进行访问 还需要先访问它的右子树 所以 再一次将该节点的地址入栈
// 只有当该结点的右子树访问完毕后回到该结点时 才能访问该结点
// 为了标明某结点是否可以访问 引入一个标志变量flag
// 当flag=0时表示该结点暂不访问
// 当flag=1时表示该结点可以访问
// flag的值随着该结点的地址一起入栈和出栈
// 因此 算法中设置了两个堆栈 一个存放二叉树结点 一存放flag标志变量 两个堆栈使用同一个栈顶指针top 初始化值是-1

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

    ~BTreeNode()
    {
        delete this->left;
        delete this->right;
    }

    void Print() { std::cout << this->data << " "; }
} BTreeNode, *BTree;

#define MAX_SIZE 100

void postOrderTraverse(BTree root)
{
    BTree stack1[MAX_SIZE], p = root;
    int   stack2[MAX_SIZE], visitFlag, top = -1;
    while (p || top != -1)
    {
        // 把结点放到栈里面 然后访问左子树
        while (p)
        {
            stack1[++top] = p;
            stack2[top]   = 0;
            p             = p->left;
        }
        // 左子树访问结束 再次回到到结点 也还不能立即访问 把右子树访问完然后才能访问该结点
        // 这个节点会被访问到3次 最后一次的时候真正读取它 用flag标识
        p         = stack1[top];
        visitFlag = stack2[top--];
        if (!visitFlag)
        {
            stack1[++top] = p;
            stack2[top]   = 1;
            p             = p->right;
        }
        else
        {
            p->Print();
            p = nullptr;
        }
    }
}

int main(int argc, const char** argv)
{
    BTree root  = new BTreeNode(1);
    root->left  = new BTreeNode(2);
    root->right = new BTreeNode(3);
    postOrderTraverse(root);
    return 0;
}