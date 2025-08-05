//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
typedef struct LinkListNode
{
    int                  data;
    struct LinkListNode* next;

    LinkListNode(int x)
    {
        this->data = x;
        this->next = nullptr;
    }

    ~LinkListNode() { delete this->next; }

    // 打印链表
    void Print()
    {
        std::cout << "链表是";
        struct LinkListNode* p = this;
        while (p)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}* LinkList;

/**
 * 将两个按值有序排列的非空线性链表合并为一个按值有序的线性链表
 * @param l1 单链表
 * @param l2 单链表
 * @return 合并结果
 */
LinkList merge(LinkList l1, LinkList l2)
{
    // r是ret中的活动指针
    // p是l1的活动指针
    // q是l2的活动指针
    LinkList ret, p = l1, q = l2, r;
    if (l1->data <= l2->data)
    {
        ret = l1;
        r   = l1;
        p   = l1->next;
    }
    else
    {
        ret = l2;
        r   = l2;
        q   = l2->next;
    }
    while (p != nullptr && q != nullptr)
    {
        if (p->data <= q->data)
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
    // l1 l2两个链表长度不一样 有一个会先遍历完 另一个就还有剩余
    r->next = (p != nullptr) ? p->next : q;
    return ret;
}

int main(int argc, const char** argv)
{
    LinkList l1    = new LinkListNode(1);
    l1->next       = new LinkListNode(2);
    l1->next->next = new LinkListNode(3);
    l1->Print();

    LinkList l2    = new LinkListNode(2);
    l2->next       = new LinkListNode(4);
    l2->next->next = new LinkListNode(5);
    l2->Print();

    LinkList ret = merge(l1, l2);
    ret->Print();
    return 0;
}