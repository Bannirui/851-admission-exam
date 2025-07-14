#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

typedef struct BTNode
{
    // 四则运算符 + - * / 或者数字
    char           data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode;

void createTree(BTNode*& T)
{
    BTNode *a, *b, *c, *d, *e, *f, *g, *h;
    T       = (BTNode*)malloc(sizeof(BTNode));
    T->data = '*';
    a       = (BTNode*)malloc(sizeof(BTNode));
    a->data = '-';
    b       = (BTNode*)malloc(sizeof(BTNode));
    b->data = '/';
    c       = (BTNode*)malloc(sizeof(BTNode));
    c->data = '2';
    d       = (BTNode*)malloc(sizeof(BTNode));
    d->data = '+';
    e       = (BTNode*)malloc(sizeof(BTNode));
    e->data = 'e';
    f       = (BTNode*)malloc(sizeof(BTNode));
    f->data = '1';
    g       = (BTNode*)malloc(sizeof(BTNode));
    g->data = '3';
    h       = (BTNode*)malloc(sizeof(BTNode));
    h->data = '4';

    T->lchild = a;
    T->rchild = b;
    a->lchild = c;
    a->rchild = d;
    b->lchild = e;
    b->rchild = f;
    c->lchild = NULL;
    c->lchild = NULL;
    d->lchild = g;
    d->rchild = h;
    e->lchild = NULL;
    e->rchild = NULL;
    f->lchild = NULL;
    f->rchild = NULL;
    g->lchild = NULL;
    g->rchild = NULL;
    h->lchild = NULL;
    h->rchild = NULL;
}

/**
 * 两个数字的四则计算
 * @param op 操作符
 */
int op(int a, char op, int b)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            std::cout << "b can not be zero" << std::endl;
            return 0;
        }
        return a / b;
    }
    else
    {
        std::cout << "not support: " << op << std::endl;
        return 0;
    }
}

int com(BTNode* T)
{
    int a, b;
    if (T == NULL) return 0;
    if (T->lchild != NULL && T->rchild != NULL)
    {
        a = com(T->lchild);
        b = com(T->rchild);
        return op(a, T->data, b);
    }
    else
        return T->data - '0';
}

int main(int argc, char** argv)
{
    BTNode* T;
    createTree(T);
    std::cout << "四则计算结果为: " << com(T) << std::endl;
    return 0;
}