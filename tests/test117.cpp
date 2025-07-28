#include <cstdlib>
#include <iostream>
//
// Created by rui ding on 2025/7/28.
//
// 实现单链表的逆转
typedef char eleType;
typedef struct listnode
{
    eleType          data;
    struct listnode* next;
} node;
node* create(int n)
{
    node* p    = (node*)malloc(sizeof(node));
    node* head = p;
    head->data = 'A';
    for (int i = 'B'; i < 'A' + n; i++)
    {
        p       = (p->next = (node*)malloc(sizeof(node)));
        p->data = i;
        p->next = NULL;
    }
    return head;
}
void print(node* head)
{
    for (; head; head = head->next)
    {
        std::cout << head->data << " ";
    }
    std::cout << std::endl;
}

/**
 * @param head 要翻转的链表
 * @param pre 要翻转的链表的前驱
 * @return 翻转好的链表
 */
node* reverse(node* head, node* pre)
{
    // 原来的顺序是pre->head->next
    // 新的顺序是next->head->pre
    node* next = head->next;
    head->next = pre;
    if (next) return reverse(next, head);
    return head;
}
int main(int argc, char** argv)
{
    node* head = create(10);
    print(head);
    head = reverse(head, nullptr);
    print(head);
    return 0;
}