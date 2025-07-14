#include <algorithm>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

// 汉诺塔一次移动记录
void op_trace(char from, char to)
{
    std::cout << "从" << from << "-->" << to << std::endl;
}

/**
 * 汉诺塔问题 a b c是柱子标识
 * 初始的时候n个盘子按照顺序全放在a上
 * 直接移动的是a和c b是辅助的柱子
 * @param n 盘子数量
 */
void hanoi(int n, char a, char b, char c)
{
    if (n <= 0)
    {
        std::cout << "ILLEGUAL ARG" << std::endl;
        return;
    }
    if (n == 1)
    {
        // 只有一个盘子 直接从a移动到c
        op_trace(a, c);
        return;
    }
    // 先把a上面n-1个临时放到b上 再把a最底下的移到c上 最后把b上面临时的移动到c上
    hanoi(n - 1, a, c, b);
    op_trace(a, c);
    hanoi(n - 1, b, a, c);
}

int main(int argc, char** argv)
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}