//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
#include <list>
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
     * 以当前节点为head的链表打印
     */
    void Print()
    {
        std::cout << "链表是";
        LinkListNode* p = this;
        while (p != nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}* LinkList;

// 逆转线性链表 迭代
void reverse(LinkList& list)
{
    // p当前节点
    // q是p的前驱 等会前驱变后继
    // r是已经翻转好的部分q的后继
    LinkList p, q, r;
    p = list;
    q = nullptr;
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        // 翻转当前的节点
        q->next = r;
    }
    list = q;
}

int main(int argc, const char** argv)
{
    LinkList list          = new LinkListNode(1);
    list->next             = new LinkListNode(2);
    list->next->next       = new LinkListNode(3);
    list->next->next->next = new LinkListNode(4);
    list->Print();
    reverse(list);
    list->Print();

    return 0;
}