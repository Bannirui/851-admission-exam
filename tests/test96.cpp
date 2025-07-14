#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>

#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#include <queue>
#endif

/**
 * 棋子
 */
class Node
{
   public:
    Node(int n);
    Node(const Node& other);

   public:
    int  t;    // 0-based 棋子放在arr[t]行 语意是这个棋子放到棋盘第t行 即[0...t]已经放好了
    int* loc;  // 长度t loc[0:t-1] 0-based 每一行第几列放棋子
    int  n;    // 共放置n个皇后

    /**
     * 已经放了t行 往下一行看看哪一列可以不冲突放棋子
     * 检测arr[t+1][next]
     * @param next 列号 1-based
     */
    bool checkNext(int next);
    void printQ();
};
Node::Node(int n) : t(-1), n(n)
{
    this->loc = new int[this->n + 1];
    for (int i = 0; i < this->n; ++i)
    {
        // 没放棋子
        this->loc[i] = -1;
    }
}
Node::Node(const Node& other)
{
    this->t   = other.t;
    this->n   = other.n;
    this->loc = new int[this->n + 1];
    for (int i = 0; i < this->n; ++i)
    {
        this->loc[i] = other.loc[i];
    }
}
bool Node::checkNext(int next)
{
    int i;
    // arr[0...t]行已经放好 看看arr[t+1][next]会不会有冲突
    for (i = 0; i <= this->t; ++i)
    {
        // arr[i][loc[i]] vs arr[t+1][next]
        if (this->loc[i] == next)
        {
            // 同列
            return false;
        }
        if (next - this->loc[i] == this->t + 1 - i)
        {
            // 斜线
            return false;
        }
    }
    return true;
}

void Node::printQ()
{
    std::cout << "摆盘方式" << " ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << this->loc[i] << " ";
    }
    std::cout << std::endl;
}

class Queen
{
   public:
    int n;       // n皇后
    int ansNum;  // n皇后解的个数

    Queen(int n);
    void ArrangeQueen();
};

Queen::Queen(int n) : n(n)
{
    this->ansNum = 0;
}
void Queen::ArrangeQueen()
{
    std::queue<Node> Q;
    Node             ini(this->n);
    Q.push(ini);  // 初始化
    while (!Q.empty())
    {
        Node father = Q.front();  // 出队
        Q.pop();
        if (father.t == n - 1)
        {
            // 棋盘上放满了皇后数量 找到了一种解决方案
            father.printQ();
            ++this->ansNum;
        }
        // 已经放好了t个棋子 也就是放好了t行 现在往t+1行看看可以放哪一列 所有有的可能位置都加到队列中
        for (int i = 0; i < this->n; ++i)
        {
            if (father.checkNext(i))
            {
                // 棋盘t+1行 i列可以放
                Node Child(father);
                // 新棋子位置arr[t+1][i]
                ++Child.t;
                Child.loc[Child.t] = i;
                Q.push(Child);
            }
        }
    }
}

int main(int argc, char** argv)
{
    int   n = 10;
    Queen Q(n);
    Q.ArrangeQueen();
    std::cout << "棋盘大小" << n << "x" << n << " 共" << Q.ansNum << "种放置皇后的方法" << std::endl;
    return 0;
}