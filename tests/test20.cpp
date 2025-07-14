#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>

// 单链表
class LinkNode
{
   public:
    // 链表结点标识
    enum color
    {
        HEAD = -1,
        RED  = 0,
        WHITE,
        BLUE
    };

   public:
    LinkNode(color data) : data(data) { this->next = NULL; }
    LinkNode(color data, LinkNode* next) : data(data), next(next) {}
    void print()
    {
        if (this->next == NULL)
            std::cout << "当前链表为空";
        else
            std::cout << "当前链表为";
        LinkNode* cur = this->next;
        while (cur != NULL)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

   public:
    color     data;
    LinkNode* next;
};

/**
 * L带头结点 将该链表中结点按照其颜色标识分类
 * p指针扫描单链表L的结点 根据p->data值将该结点插入到3个单链表L L1 L2中
 * L1和L2不带头结点
 * 均采用尾插法 最后将链表链接起来
 */
void HollandFlag(LinkNode* L)
{
    /**
     * pre 遍历L链表维护的前驱结点
     * p 遍历L链表的结点
     *
     * L1 链表 放白色结点
     * p1 遍历L1链表维护的前驱结点
     *
     * L2 链表 放蓝色结点
     * p2 遍历L2链表维护的前驱结点
     */
    LinkNode *L1, *L2, *pre, *p, *p1, *p2;
    // 两个不带头结点的链表
    L1 = NULL;
    L2 = NULL;
    // 扫描链表L的结点 pre指向p的前驱结点
    pre = L;
    p   = pre->next;
    while (p)
    {
        if (p->data == LinkNode::color::RED)
        {
            // 红色 依然归在当前L链表上
            pre->next = p;
            pre       = p;
        }
        else if (p->data == LinkNode::color::WHITE)
        {
            // 白色 插入L1链表
            if (!L1)
            {
                // 初始化链表
                L1 = p;
                p1 = p;
            }
            else
            {
                p1->next = p;
                p1       = p;
            }
        }
        else
        {
            // 蓝色 插入L2链表
            if (!L2)
            {
                // 初始化链表
                L2 = p;
                p2 = p;
            }
            else
            {
                p2->next = p;
                p2       = p;
            }
        }
        // 待考察的下一个结点
        p = p->next;
    }
    // 3条链表的尾结点next都指向NULL
    pre->next = p1->next = p2->next = NULL;
    // 3条链表链接起来
    pre->next = L1;
    p1->next  = L2;
}

int main(int argc, char** argv)
{
    LinkNode l9 = LinkNode(LinkNode::color::BLUE);
    LinkNode l8 = LinkNode(LinkNode::color::WHITE, &l9);
    LinkNode l7 = LinkNode(LinkNode::color::RED, &l8);
    LinkNode l6 = LinkNode(LinkNode::color::BLUE, &l7);
    LinkNode l5 = LinkNode(LinkNode::color::WHITE, &l6);
    LinkNode l4 = LinkNode(LinkNode::color::RED, &l5);
    LinkNode l3 = LinkNode(LinkNode::color::BLUE, &l4);
    LinkNode l2 = LinkNode(LinkNode::color::WHITE, &l3);
    LinkNode l1 = LinkNode(LinkNode::color::HEAD, &l2);
    l1.print();
    HollandFlag(&l1);
    l1.print();
    return 0;
}