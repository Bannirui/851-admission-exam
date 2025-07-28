//
// Created by rui ding on 2025/7/24.
//
// 现在小明一家过一座桥 过桥的时候是黑夜 所以必须有灯
// 小明过桥要1分钟
// 小明的弟弟要3分钟
// 小明的爸爸要6分钟
// 小明的妈妈要8分钟
// 小明的爷爷要12分钟
// 每次过桥最多2个人 过桥的速度由最慢的决定 而且在灯点燃后30分钟就会熄灭
// 怎么过桥时间最短

#include <iostream>

// 总共5个人要过桥
// 将人员编号 0-小明 1-弟弟 2-爸爸 3-妈妈 4-爷爷
#define N 5
// 每个人的当前位置 0-在桥左边 1-在桥右边
int pos[N] = {0};
#define SZ 64
// 临时方案的脚标
int idx;
// 临时方案 里面放在就是过桥顺序的人员id
int tmpScheme[SZ];
// 最优方案 放的是人员id
int scheme[SZ];
// 过桥最小耗时
int minCost = 100;
// 每个人过桥耗时
int timeCost[N] = {1, 3, 6, 8, 12};

// 过桥的方向
enum class Direction
{
    // 折返回来 送灯火
    BACK = 0,
    // 过桥
    PASS = 1,
};

/**
 * @param remain 还有多少人没过桥 多少个人需要过桥
 * @param curCost 已经用了多少时间
 * @param direction 过桥场景 0-向左 1-向右
 */
void find(int remain, int curCost, Direction direction)
{
    if (remain == 0)
    {
        // 所有人已经过桥
        minCost = curCost;
        // scheme数组里面放的是人员的id 应该是>=0
        for (int i = 0; i < SZ && tmpScheme[i] >= 0; i++)
        {
            scheme[i] = tmpScheme[i];
        }
        return;
    }
    if (direction == Direction::PASS)
    {
        // 从桥左边找出2个人过桥
        for (int i = 0; i < N; i++)
        {
            if (pos[i] == 0 && (curCost + timeCost[i]) < minCost)
            {
                // 找到了过桥的第1个人
                tmpScheme[idx++] = i;
                pos[i]           = 1;
                for (int j = 0; j < N; j++)
                {
                    // 过桥时间由耗时高的那个人决定的
                    int tmpMax = (timeCost[i] > timeCost[j]) ? timeCost[i] : timeCost[j];
                    if (pos[j] == 0 && (curCost + tmpMax) < minCost)
                    {
                        // 找到了过桥的两个人是i跟j
                        tmpScheme[idx++] = j;
                        pos[j]           = 1;
                        // 递归
                        find(remain - 2, curCost + tmpMax, Direction::BACK);
                        pos[j]           = 0;
                        tmpScheme[--idx] = -1;
                    }
                }
                pos[i]           = 0;
                tmpScheme[--idx] = -1;
            }
        }
    }
    else
    {
        // 过桥方向是向左 从桥的右边找出1个人回来送灯
        for (int j = 0; j < N; j++)
        {
            if (pos[j] == 1 && (curCost + timeCost[j]) < minCost)
            {
                tmpScheme[idx++] = j;
                pos[j]           = 0;
                find(remain + 1, curCost + timeCost[j], Direction::PASS);
                pos[j]           = 1;
                tmpScheme[--idx] = -1;
            }
        }
    }
}

int main(int argc, char** argv)
{
    // 方案初始负数 避免跟人员脚标冲突
    for (int i = 0; i < SZ; i++)
    {
        scheme[i] = -1;
    }
    // 查找最佳方案
    find(N, 0, Direction::PASS);
    std::cout << "Minimum cost = " << minCost << "\n";
    // 输出最佳方案
    for (int i = 0; i < SZ && scheme[i] >= 0; i += 3)
    {
        std::cout << scheme[i] << "-" << scheme[i + 1] << " " << scheme[i + 2] << std::endl;
    }
    return 0;
}