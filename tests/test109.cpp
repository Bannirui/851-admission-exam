//
// Created by rui ding on 2025/7/21.
//

#include <iostream>
// 有4种面值的邮票很多枚 这4种邮票面值分别是1 4 12 21 现在从多张中最多任取5张进行组合
// 求取出这些邮票的最大连续组合值
// 最多拿5张
#define N 5
// Flag存放拿了哪些邮票 邮票0号索引是守卫 表示没拿邮票
int k, Found, Flag[N];
// 邮票面值
#define M 5
// 0是守卫
int Stamp[M] = {0, 1, 4, 12, 21};
// 在剩余张数n中组合出面值和value
/**
 * @param n 总共可以拿几张邮票
 * @param value 要组合出面值多少
 */
int combine(int n, int value)
{
    if (n >= 0 && value == 0)
    {
        // 找到了一种方案
        Found   = 1;
        int Sum = 0;
        for (int i = 0; i < N && Flag[i] != 0; i++)
        {
            Sum += Stamp[Flag[i]];
            std::cout << Stamp[Flag[i]] << std::endl;
        }
        std::cout << "Sum=" << Sum << std::endl;
    }
    else
    {
        for (int i = 1; i < M && !Found && n > 0; i++)
        {
            if (value - Stamp[i] >= 0)
            {
                // 当前这张邮票拿了 继续递归拿
                Flag[k++] = i;
                combine(n - 1, value - Stamp[i]);
                // 恢复现场
                Flag[--k] = 0;
            }
        }
    }
    return Found;
}
int main(int argc, char** argv)
{
    for (int i = 1; combine(N, i); i++, Found = 0);
}