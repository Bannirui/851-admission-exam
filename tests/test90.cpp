#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

/**
 * 题目
 * 有一个带头结点的乱序单链表 已知该单链表中的关键字取值范围为0-999 且单链表的总长度n非常大
 * 请设计一个时间上尽可能高效算法 将单链表L排成升序序列 指针L指向头结点
 *
 * 算法思想
 * 可采用基数排序的思想 关键字取值范围为0-999 最终需要得到一个升序序列
 * 总共进行3趟分配与回收 另外需建立10个辅助队列list[10]
 * 第一趟分配 顺序摘下单链表中的各个结点 以结点关键字个位为依据 若个位值为d 则将该结点插入到队列list[d]的队尾
 * 第一趟回收 按照list[9]-list[0]的顺序将10个队列整体插入到单链表L的链头 头插法
 * 第二趟分配 顺序摘下单链表的各个结点 以结点关键字十位为依据 若十位值为d 则将该结点插入到队列list[d]的队尾
 * 第二趟回收 按照list[9]-list[0]的顺序将10个队列整体插入到单链表的链头
 * 第三趟分配 顺序摘下单链表的各个结点 以结点关键字百位为依据 若百位值为d 则结点插入到队列list[d]的队尾
 * 第三趟回收 按照list[9]-list[0]的顺序将10个队列整体插入到单链表L的链头
 * 经过三趟分配 回收 即可得到升序单链表L
 *
 * 时间复杂度 O(N)
 * 空间复杂度 O(1)
 * 算法稳定性 稳定
 */

// 用于存储关键字的结点
typedef struct Node
{
    int          key;
    struct Node* next;
} Node;

// 队列结点的定义
typedef struct
{
    Node* front;  // 队头指针
    Node* rear;   // 队尾指针
} Queue;

/**
 * 十进制数的第d位
 * @param key 目标十进制数
 * @param d 十进制的第d位 1-based 1表示个位 2表示十位 3表示百位
 */
int getRadix(int key, int d)
{
    if (d == 1) return key % 10;
    if (d == 2) return (key / 10) % 10;
    if (d == 3) return (key / 100) % 10;
    return -1;  // 参数有误
}

/**
 * 第k趟分配 链表中关键字按照第k位上数字排序 放到list中
 * @param L 单链表的哨兵结点
 * @param k 第几趟分配 1-based
 * @param list 基数排序的桶 0-9p
 */
void distribute(Node* L, int k, Queue list[])
{
    // 每次摘下链头元素进行分配
    while (L->next != NULL)
    {
        // 数据结点
        Node* p = L->next;
        L->next = p->next;
        p->next = NULL;
        // 每一趟排一个十进制位 第一趟排个位 第二趟排十位... 找到关键字对应位上的数字
        int r = getRadix(p->key, k);
        if (list[r].front == NULL)
        {
            // 队列为空
            list[r].front = p;
            list[r].rear  = p;
        }
        else
        {
            // 队列不空 尾插法
            list[r].rear->next = p;
            list[r].rear       = p;
        }
    }
}

/**
 * 第k趟回收
 * @param L 单链表的哨兵结点 此时单链表是空的 没有数据结点
 * @param list 基数排序的桶 已经按照关键字的某个位排序好了
 */
void collect(Node* L, int k, Queue list[])
{
    // 排序桶里面的关键字再一个一个挂到单链表上
    for (int i = 9; i >= 0; --i)
    {
        if (list[i].front == NULL) continue;  // 桶是空的
        // 桶里面有关键字 头插法到单链表上
        list[i].rear->next = L->next;
        L->next            = list[i].front;
        list[i].front      = NULL;
        list[i].rear       = NULL;
    }
}

// 对单链表L进行基数排序 其中指针L指向头结点
int RadixSort(Node* L)
{
    // 基数肯定是0-9
    Queue list[10];
    for (int i = 0; i < 10; ++i)
    {
        list[i].front = NULL;
        list[i].rear  = NULL;
    }
    // 由于关键字取值范围为0-999 因此仅需3趟分配/回收
    for (int r = 1; r <= 3; ++r)
    {
        // 按照关键字的各个位排序
        distribute(L, r, list);
        // 按照某位排好序后再挂回到单链表
        collect(L, r, list);
    }
    return 0;
}

/**
 * 单链表打印
 * @param head 链表的哨兵结点
 */
void print(Node* head)
{
    std::cout << "链表打印 ";
    Node* p = head->next;
    while (p != NULL)
    {
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

Node* init(int v)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->key  = v;
    p->next = NULL;
    return p;
}

int main(int argc, char** argv)
{
    Node* head = init(-1);
    Node* n1   = init(11);
    Node* n2   = init(9);
    Node* n3   = init(25);
    Node* n4   = init(18);
    Node* n5   = init(4);
    head->next = n1;
    n1->next   = n2;
    n2->next   = n3;
    n3->next   = n4;
    n4->next   = n5;
    std::cout << "排序前 ";
    print(head);
    RadixSort(head);
    std::cout << "基数排序后 ";
    print(head);
    return 0;
}