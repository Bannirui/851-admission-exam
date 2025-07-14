#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 100

typedef struct LNode
{
    int           data;
    struct LNode* next;
} LNode;

/**
 * @return 1标识成功
 */
int initLNode1(LNode*& head)
{
    int    arr[4] = {1, 3, 5, 7};
    int    i;
    LNode *s, *r;
    head       = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    r          = head;
    for (i = 0; i < 4; ++i)
    {
        s       = (LNode*)malloc(sizeof(LNode));
        s->data = arr[i];
        r->next = s;
        r       = r->next;
    }
    r->next = NULL;
    return 1;
}

/**
 * @return 1标识成功
 */
int initLNode2(LNode*& head)
{
    int    arr[6] = {2, 3, 6, 8, 9, 10};
    int    i;
    LNode *s, *r;
    head       = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    r          = head;
    for (i = 0; i < 6; ++i)
    {
        s       = (LNode*)malloc(sizeof(LNode));
        s->data = arr[i];
        r->next = s;
        r       = r->next;
    }
    r->next = NULL;
    return 1;
}

/**
 * @return 1标识成功
 */
int merge(LNode* A, LNode* B, LNode*& C)
{
    LNode* p = A->next;
    LNode* q = B->next;
    LNode* s;
    C       = A;
    C->next = NULL;
    free(B);
    s = C;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            s->next = p;
            s       = s->next;
            p       = p->next;
        }
        else
        {
            s->next = q;
            s       = s->next;
            q       = q->next;
        }
    }
    s->next = NULL;
    if (q == NULL) s->next = p;
    if (p == NULL) s->next = q;
    return 1;
}

int main(int argc, char** argv)
{
    LNode *A, *a, *B, *b, *C, *c;
    A = (LNode*)malloc(sizeof(LNode));
    B = (LNode*)malloc(sizeof(LNode));
    C = (LNode*)malloc(sizeof(LNode));
    initLNode1(A);
    initLNode2(B);
    a = A;
    b = B;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << a->data << "..";
        a = a->next;
    }
    std::cout << std::endl;
    for (int i = 0; i < 7; ++i)
    {
        std::cout << b->data << "..";
        b = b->next;
    }
    std::cout << std::endl;

    merge(A, B, C);
    c = C;
    for (int i = 0; i < 11; ++i)
    {
        std::cout << c->data << "..";
        c = c->next;
    }
    std::cout << std::endl;

    return 0;
}