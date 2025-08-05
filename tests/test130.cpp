//
// Created by rui ding on 2025/8/5.
//

#include <cstdlib>
#include <iostream>
// 删除线性表中数据域为item的所有结点
// 算法思想 先从链表的第2个结点开始 从前往后依次判断链表中的所有结点是否满足条件
// 若某个结点的数据域为item 则删除该结点 最后再回头判断链表中的第1个结点是否满足条件 若满足则将其删除
typedef struct LinkListNode
{
    int                  data;
    struct LinkListNode* next;

    ~LinkListNode() = default;
    LinkListNode(int data) { this->data = data; }

    /**
     * 打印链表
     */
    void Print()
    {
        struct LinkListNode* head = this;
        std::cout << "链表是";
        while (head)
        {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
} LinkListNode, *LinkList;

/**
 * 把链表上结点值是item的结点删除
 * @param list 链表
 * @param item 要删除的值
 */
void purgeItem(LinkList& list, int item)
{
    LinkList p, q = list;
    p = list->next;
    while (p)
    {
        if (p->data == item)
        {
            // 找到了要删除的结点
            q->next = p->next;
            delete p;
            p = q->next;
        }
        else
        {
            // 结点不用删除
            q = p;
            p = p->next;
        }
    }
    if (list->data == item)
    {
        q    = list;
        list = list->next;
        delete q;
    }
}

int main(int argc, char** argv)
{
    // 链表1 1 2 3
    LinkList l1          = new LinkListNode(1);
    l1->next             = new LinkListNode(1);
    l1->next->next       = new LinkListNode(2);
    l1->next->next->next = new LinkListNode(3);
    l1->Print();
    purgeItem(l1, 1);
    l1->Print();
    return 0;
}