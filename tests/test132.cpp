//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
// 链表结点
typedef struct LinkListNode
{
    int                  data;
    struct LinkListNode* next;

    LinkListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~LinkListNode() { delete this->next; }

    /**
     * 链表打印
     */
    void Print()
    {
        LinkListNode* p = this;
        std::cout << "链表是";
        while (p)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}* LinkList;

// 复制线性链表 递归
LinkList copy(LinkList head)
{
    LinkList ret;
    if (head == nullptr) return nullptr;
    ret       = (LinkList)malloc(sizeof(LinkListNode));
    ret->data = head->data;
    ret->next = copy(head->next);
    return ret;
}

int main(int argc, const char** argv)
{
    // 初始化单链表
    LinkList head    = new LinkListNode(1);
    head->next       = new LinkListNode(2);
    head->next->next = new LinkListNode(3);
    head->Print();
    // 复制链表
    LinkList ret = copy(head);
    ret->Print();
    return 0;
}