//
// Created by rui ding on 2025/7/22.
//
// 8皇后问题 输出所有情况
#define N 8
#include <iostream>
int Board[N][N];

/**
 * 判读棋盘上[i,j]是否有效 当前位置能不能下棋
 * 此时自己的右边 下边都还没下棋 只要判读左边和上边
 * @return 0-无效
 */
int valid(int i, int j)
{
    int k = 1;
    for (k = 1; i - k >= 0 && j - k >= 0; k++)
    {
        // 左上方对角线有没有下棋
        if (Board[i - k][j - k]) return 0;
    }
    for (k = 1; i - k >= 0 && j + k < N; k++)
    {
        // 右上方对角线有没有下棋
        if (Board[i - k][j + k]) return 0;
    }
    // 同一行上 左边有没有下过棋
    for (k = 1; j - k >= 0; k++)
    {
        if (Board[i][j - k]) return 0;
    }
    // 同一列上 上边有没有下过棋
    for (k = 1; i - k >= 0; k++)
    {
        if (Board[i - k][j]) return 0;
    }
    return 1;
}

// 打印棋盘摆棋方案 棋盘规模是rows*rows
void print(const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << Board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
/**
 * 寻找合适位置下棋
 * @param i 现在下的是第几行
 * @param n 总共多少行
 */
void trial(int i, int n)
{
    // base
    if (i == n)
    {
        // 找到了下棋的一种方案 遍历棋盘打印
        print(n);
        return;
    }
    // 在i行 遍历所有列 看看哪个地方可以下
    for (int j = 0; j < n; j++)
    {
        // 在这个位置下
        Board[i][j] = 1;
        if (valid(i, j))
        {
            trial(i + 1, n);
        }
        // 恢复现场
        Board[i][j] = 0;
    }
}

// 初始化棋盘
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Board[i][j] = 0;
        }
    }
}
int main(int argc, char** argv)
{
    init();
    // 从第1行开始摆棋
    trial(0, N);
    return 0;
}