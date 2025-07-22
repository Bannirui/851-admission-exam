//
// Created by rui ding on 2025/7/22.
//
// 4个工人 4个任务 每个人做不同的任务需要的时间不同 求任务分配的最优方案
#define N 4
#include <iostream>
// 行 任务序号
// 列 工人序号
// 每个任务每个工人的耗时
// clang-format off
int Cost[N][N] = {
    {2, 1, 5, 32},
    {8, 15, 7, 11},
    {24, 18, 9, 6},
    {21, 1, 8, 28},
};
// clang-format on
int MinCost = 1000;
// 任务分配给了谁 key-任务 val-工人索引
int Task[N];
// 缓存分配方案 key-任务 val-工人索引
int taskRet[N];
// 标识工人是不是已经排上了任务 0表示空闲 1表示排上了任务
int Worker[N];

/**
 * @param k 任务编号 0-based
 * @param cost 已经耗时
 */
void assign(int k, int cost)
{
    if (k == N)
    {
        // 任务排完了 统计耗时
        MinCost = cost;
        for (int i = 0; i < N; i++)
        {
            taskRet[i] = Task[i];
        }
        return;
    }
    // 开始排任务k
    for (int i = 0; i < N; i++)
    {
        // 看看所有工人的安排情况 找空闲的工人
        if (Worker[i] == 0 && cost + Cost[k][i] < MinCost)
        {
            // 找到了耗时更少的分配方案
            Worker[i] = 1;
            Task[k]   = i;
            assign(k + 1, cost + Cost[k][i]);
            // 恢复现场
            Worker[i] = 0;
            Task[k]   = 0;
        }
    }
}
int main(int argc, char** argv)
{
    assign(0, 0);
    std::cout << "最佳方案总费用=" << MinCost << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "任务" << i << "由工人" << taskRet[i] << "来做" << std::endl;
    }
    return 0;
}