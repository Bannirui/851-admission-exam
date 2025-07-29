#include <cstdlib>
#include <iostream>
//
// Created by rui ding on 2025/7/29.
//
// 判断单链表中是否存在环
typedef char eleType;
typedef struct listnode
{
    eleType          data;
    struct listnode* next;
} node;

// 创建n个节点的单链表 没有哨兵都是数据节点
node* create(int n)
{
    node* p    = (node*)malloc(sizeof(node));
    node* head = p;
    head->data = 'A';
    for (int i = 'B'; i < 'A' + n; i++)
    {
        p       = (p->next = (node*)malloc(sizeof(node)));
        p->data = i;
        p->next = nullptr;
    }
    return head;
}

// 增加环 将链表尾指向链表中第n个节点
void addCircle(node* head, int n)
{
    node *q, *p = head;
    for (int i = 1; p->next; i++)
    {
        if (i == n) q = p;
        p = p->next;
    }
    p->next = q;
}

int isCircle(node* head)
{
    // 快慢指针 快指针步进值2 慢指针步进值1 相遇在环点
    node *p = head, *q = head;
    while (p->next && q->next)
    {
        p = p->next;
        if (NULL == (q = q->next->next)) return 0;
        if (p == q) return 1;
    }
    return 0;
}

int main(int argc, const char** argv)
{
    node* head = create(5);
    std::cout << "添加前 " << isCircle(head) << std::endl;
    addCircle(head, 3);
    std::cout << "添加后 " << isCircle(head) << std::endl;
    return 0;
}