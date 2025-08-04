#include "../src/list/MyList.h"

#include <iostream>
//
// Created by rui ding on 2025/8/1.
//
// 写一个算法将两个有序的单链表合并为一个有序的单链表
// A B C指向的链表都是带头节点的单链表
typedef int Type;
typedef struct LNode
{
    Type          data;
    struct LNode* next;
} LNode;

bool merge(LNode* A, LNode* B, LNode*& C)
{
    C = new LNode;
    if (!C) return false;
    LNode *p = A->next, *q = B->next, *r = C;
    while (p && q)
    {
        if ((int)p->data <= (int)q->data)
        {
            r->next = p;
            r       = p;
            p       = p->next;
        }
        else
        {
            r->next = q;
            r       = q;
            q       = q->next;
        }
    }
    if (p) r->next = p;
    if (q) r->next = q;
    delete A;
    delete B;
    return true;
}

// 带头节点的单链表
void print(LNode* head)
{
    std::cout << "链表是 ";
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void init(LNode* head, int arr[], int sz)
{
    LNode* p = head;
    for (int i = 0; i < sz; i++)
    {
        LNode* cur = (LNode*)malloc(sizeof(LNode));
        cur->data  = arr[i];
        cur->next  = NULL;
        p->next    = cur;
        p          = p->next;
    }
}
int main(int argc, const char** argv)
{
    int    arr1[] = {2, 4, 6};
    int    arr2[] = {1, 3, 5, 7};
    LNode* l1     = (LNode*)malloc(sizeof(LNode));
    LNode* l2     = (LNode*)malloc(sizeof(LNode));
    init(l1, arr1, 3);
    print(l1);
    init(l2, arr2, 4);
    print(l2);
    LNode* l3 = (LNode*)malloc(sizeof(LNode));
    merge(l1, l2, l3);
    print(l3);
    return 0;
}