//
// Created by rui ding on 2025/7/17.
//
// 寻找迷宫的一条出路
// o-通路
// X-障碍

#define MAX_SZ 8
#include <cstdio>

// 水平方向和垂直方向组合就是上下左右4个方向
int H[4] = {1, 0, 0, -1};
int V[4] = {0, 1, -1, 0};
// clang-format off
// 8*8
char Maze[MAX_SZ][MAX_SZ] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'o', 'o', 'o', 'o', 'o', 'X', 'X', 'X'},
    {'X', 'o', 'X', 'X', 'o', 'o', 'o', 'X'},
    {'X', 'o', 'X', 'X', 'o', 'X', 'X', 'o'},
    {'X', 'o', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'o', 'X', 'X', 'o', 'o', 'o', 'X'},
    {'X', 'o', 'o', 'o', 'o', 'X', 'o', 'o'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
};
// clang-format on

// 数组打印
void PrintArr()
{
    for (int i = 0; i < MAX_SZ; i++)
    {
        for (int j = 0; j < MAX_SZ; j++)
        {
            printf("%c%c", Maze[i][j], j < MAX_SZ - 1 ? ' ' : '\n');
        }
    }
}

// 从[X,Y]坐标点出发找通路
void FindPath(int X, int Y)
{
    // 走到了边界
    if (X == MAX_SZ || Y == MAX_SZ)
    {
        PrintArr();
        return;
    }
    // 当前在[x,y] 上下左右4个方向尝试
    for (int k = 0; k < 4; k++)
    {
        if (X >= 0 && Y >= 0 && Y < MAX_SZ && X < MAX_SZ && 'o' == Maze[X][Y])
        {
            // 找到了能通的路 置空表示走过了
            Maze[X][Y] = ' ';
            // 开始尝试其他方向
            FindPath(X + V[k], Y + H[k]);
            // 恢复现场
            Maze[X][Y] = 'o';
        }
    }
}

int main(int argc, char** argv)
{
    FindPath(1, 1);
    return 0;
}
