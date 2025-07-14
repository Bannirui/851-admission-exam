#include <iostream>

#define maxSize 20

typedef struct BTNode
{
    int            val;
    int            ltag, rtag;
    struct BTNode *left, *right;
} BTNode;
typedef struct Cn
{
    int     lno;
    BTNode* p;
} Cn;
void createTree(BTNode*& t)
{
    t      = (BTNode*)malloc(sizeof(BTNode));
    t->val = 1;

    BTNode *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
    a      = (BTNode*)malloc(sizeof(BTNode));
    a->val = 2;
    b      = (BTNode*)malloc(sizeof(BTNode));
    b->val = 3;
    c      = (BTNode*)malloc(sizeof(BTNode));
    c->val = 4;
    d      = (BTNode*)malloc(sizeof(BTNode));
    d->val = 5;
    e      = (BTNode*)malloc(sizeof(BTNode));
    e->val = 6;
    f      = (BTNode*)malloc(sizeof(BTNode));
    f->val = 7;
    g      = (BTNode*)malloc(sizeof(BTNode));
    g->val = 8;
    h      = (BTNode*)malloc(sizeof(BTNode));
    h->val = 9;
    i      = (BTNode*)malloc(sizeof(BTNode));
    i->val = 10;
    j      = (BTNode*)malloc(sizeof(BTNode));
    j->val = 11;
    k      = (BTNode*)malloc(sizeof(BTNode));
    k->val = 12;

    t->ltag  = 0;
    t->rtag  = 0;
    t->left  = a;
    t->right = b;

    a->ltag  = 0;
    a->rtag  = 0;
    a->left  = c;
    a->right = d;

    b->ltag  = 0;
    b->rtag  = 0;
    b->left  = e;
    b->right = f;

    c->ltag  = 0;
    c->rtag  = 0;
    c->left  = g;
    c->right = h;

    d->ltag  = 0;
    d->rtag  = 0;
    d->left  = nullptr;
    d->right = i;

    e->ltag  = 0;
    e->rtag  = 0;
    e->left  = nullptr;
    e->right = j;

    f->ltag  = 0;
    f->rtag  = 0;
    f->left  = nullptr;
    f->right = nullptr;

    g->ltag  = 0;
    g->rtag  = 0;
    g->left  = nullptr;
    g->right = nullptr;

    h->ltag  = 0;
    h->rtag  = 0;
    h->left  = nullptr;
    h->right = nullptr;

    i->ltag  = 0;
    i->rtag  = 0;
    i->left  = nullptr;
    i->right = nullptr;

    j->ltag  = 0;
    j->rtag  = 0;
    j->left  = k;
    j->right = nullptr;

    k->ltag  = 0;
    k->rtag  = 0;
    k->left  = nullptr;
    k->right = nullptr;
}
/**
 * 二叉树的前序遍历
 */
void preorder(BTNode* root)
{
    if (root == nullptr) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
/**
 * 二叉树的中序遍历
 */
void inorder(BTNode* root)
{
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}
/**
 * 二叉树的中序遍历
 */
void postorder(BTNode* root)
{
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}
void preorder_2(BTNode* root)
{
    if (root == nullptr) return;
    BTNode *stack[maxSize], *s;
    int     top  = -1;
    stack[++top] = root;
    while (top != -1)
    {
        s = stack[top--];
        std::cout << s->val << " ";
        if (s->right != nullptr) stack[++top] = s->right;
        if (s->left != nullptr) stack[++top] = s->left;
    }
}
void inorder_2(BTNode* root)
{
    if (root == nullptr) return;
    BTNode* stack[maxSize];
    int     top = -1;
    while (top != -1 || root != nullptr)
    {
        while (root != nullptr)
        {
            // 入栈
            stack[++top] = root;
            root         = root->left;
        }
        while (top != -1)
        {
            // 出栈
            root = stack[top--];
            std::cout << root->val << " ";
            root = root->right;
        }
    }
}
void postorder_2(BTNode* root)
{
    if (root == nullptr) return;
    BTNode *stack1[maxSize], *stack2[maxSize], *s;
    int     top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1)
    {
        s              = stack1[top1--];
        stack2[++top2] = s;
        if (s->left != nullptr) stack1[++top1] = s->left;
        if (s->right != nullptr) stack1[++top1] = s->right;
    }
    while (top2 != -1)
    {
        std::cout << stack2[top2--]->val << " ";
    }
}
/**
 * 二叉树层序遍历
 */
void levelOrder(BTNode* root)
{
    if (root == nullptr) return;
    BTNode *queue[maxSize], *s;
    int     front = 0, rear = 0;
    /**
     * 数组实现循环队列
     * 牺牲一个空间用于标识队列是满还是空的状态
     * 空-front==rear
     * 满-front+1==rear
     */
    rear        = (rear + 1) % maxSize;
    queue[rear] = root;
    while (front != rear)
    {
        front = (front + 1) % maxSize;
        s     = queue[front];
        std::cout << s->val << " ";
        if (s->left != nullptr)
        {
            rear        = (rear + 1) % maxSize;
            queue[rear] = s->left;
        }
        if (s->right != nullptr)
        {
            rear        = (rear + 1) % maxSize;
            queue[rear] = s->right;
        }
    }
}
/**
 * 递归计算树高 叶子节点1-based
 */
int getDepth(BTNode* root)
{
    // base
    if (root == nullptr) return 0;
    int l, r;
    l = getDepth(root->left);
    r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}
int maxWidth(BTNode* root)
{
    if (root == nullptr) return 0;
    int front = 0, rear = 0, Lno, max = 0, sum = 1;
    Cn  queue[maxSize], s;
    rear            = (rear + 1) % maxSize;
    queue[rear].p   = root;
    queue[rear].lno = 1;
    while (rear != front)
    {
        front = (front + 1) % maxSize;
        s     = queue[front];
        Lno   = s.lno;
        if (s.p->left != nullptr)
        {
            rear            = (rear + 1) % maxSize;
            queue[rear].p   = s.p->left;
            queue[rear].lno = Lno + 1;
        }
    }
    for (int i = 1; i < rear; ++i)
    {
        if (queue[i].lno == queue[i + 1].lno)
            ++sum;
        else
        {
            if (sum > max) max = sum;
            sum = 1;
        }
    }
    return max;
}
void findK(BTNode* root, BTNode*& q, int key)
{
    if (root == nullptr) return;
    if (root->val == key)
    {
        q = root;
        return;
    }
    else
    {
        findK(root->left, q, key);
        findK(root->right, q, key);
    }
}
void inThread(BTNode* root, BTNode*& pre)
{
    if (root == nullptr) return;
    inThread(root->left, pre);
    if (root->left == nullptr)
    {
        root->left = pre;
        root->ltag = 1;
    }
    if (pre != nullptr && pre->right == nullptr)
    {
        pre->right = root;
        pre->rtag  = 1;
    }
    pre  = root;
    root = root->right;
    inThread(root, pre);
}
BTNode* first(BTNode* p)
{
    while (p->ltag == 0) p = p->left;
    return p;
}
BTNode* next(BTNode* p)
{
    if (p->rtag == 0) return first(p->right);
    return p->right;
}

BTNode* st[maxSize];
int     t = -1;
void    dipp()
{
    for (int i = 0; i <= t; ++i)
    {
        std::cout << st[i]->val << " ";
    }
    std::cout << std::endl;
}
void dispTrace(BTNode* root)
{
    if (root == nullptr) return;
    st[++t] = root;
    if (root->left == nullptr && root->right == nullptr) dipp();
    dispTrace(root->left);
    dispTrace(root->right);
    --t;
}
int main(int argc, char** argv)
{
    BTNode *T, *s, *pre = nullptr;
    createTree(T);
    dispTrace(T);
    std::cout << std::endl;

    std::cout << "前序 ";
    preorder(T);
    std::cout << std::endl;

    std::cout << "前序2 ";
    preorder_2(T);
    std::cout << std::endl;

    std::cout << "中序 ";
    inorder(T);
    std::cout << std::endl;

    std::cout << "中序2 ";
    inorder_2(T);
    std::cout << std::endl;

    std::cout << "后序 ";
    postorder(T);
    std::cout << std::endl;

    std::cout << "后序2 ";
    postorder_2(T);
    std::cout << std::endl;

    std::cout << "层序 ";
    levelOrder(T);
    std::cout << std::endl;

    std::cout << "树高 ";
    getDepth(T);
    std::cout << std::endl;

    std::cout << "数宽 ";
    maxWidth(T);
    std::cout << std::endl;

    findK(T, s, 5);
    std::cout << "key is " << s->val << std::endl;

    if (T != nullptr)
    {
        inThread(T, pre);
        pre->right = nullptr;
        pre->rtag  = 1;
    }

    for (BTNode* p = first(T); p != nullptr; p = next(p)) std::cout << p->val;
    std::cout << std::endl;
    return 0;
}