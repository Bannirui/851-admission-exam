#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

typedef struct LNode
{
    int           data;
    struct LNode* next;
} LNode;

void initStack(LNode*& st)
{
    st       = (LNode*)malloc(sizeof(LNode));
    st->next = NULL;
}

int isEmpty(LNode* st)
{
    if (st->next == NULL) return 1;
    return 0;
}

/**
 * 单链表头插.
 * @param st 单链表的哨兵节点
 */
void push(LNode*& st, int x)
{
    LNode* s;
    s        = (LNode*)malloc(sizeof(LNode));
    s->data  = x;
    s->next  = NULL;
    s->next  = st->next;
    st->next = s;
}

int pop(LNode*& st, int& e)
{
    LNode* r;
    if (st->next == NULL) return 0;

    r        = st->next;
    st->next = r->next;
    e        = r->data;
    free(r);
    return 1;
}

int main(int argc, char** argv)
{
    LNode *st, *r;
    initStack(st);
    std::cout << "is empty: " << isEmpty(st) << std::endl;
    push(st, 3);
    push(st, 6);
    r = st;
    std::cout << "链表元素为 ";
    while (r->next != NULL)
    {
        std::cout << r->next->data << " ";
        r = r->next;
    }
    std::cout << std::endl;
    return 0;
}