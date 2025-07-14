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

#define MAX_SZ 20
#define INF 1000

typedef struct VexNode
{
    int no;
} VexNode;

typedef struct MGraph
{
    // 图的邻接矩
    int     edges[MAX_SZ][MAX_SZ];
    VexNode vex[MAX_SZ];
    // 顶点数量和边的数量
    int v, e;
} MGraph;

// 矩阵 图中边 INF表示两点没有连通
int edgesW[5][5] = {
    {INF, 5, 1, 2, INF}, {5, INF, 4, INF, 4}, {1, 3, INF, 6, 2}, {2, INF, 6, INF, 3}, {INF, 4, 2, 3, INF}};

/**
 * 开始的时候dist和path都是空的
 * @param v 源点
 * @param dist 用于缓存图中点到源点的最短距离
 *             dist[i]的语义是i到源点v的距离
 * @param path 用于缓存到源点最短的距离以及对应的点
 *             path[i]的语义是i到源的距离最短为path[i]
 */
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
    // 标识顶点是否访问过 0表示还没访问过 1表示已经访问过
    int visit[MAX_SZ];
    // 用来缓存到v点最近的是哪个点
    int u;
    // 遍历顶点 当前源点v可以到达的所有顶点
    for (int i = 0; i < g.v; ++i)
    {
        dist[i]  = g.edges[v][i];
        visit[i] = 0;
        if (dist[i] < INF)
            path[i] = v;  // 说明v到i可以直达
        else
            path[i] = -1;  // 顶点v到i不可直达
    }
    // 源点先加到结果集
    visit[v] = 1;
    // 图中总共n个点 已经有了源点v 只要找剩下的n-1个点
    for (int i = 0; i < g.v - 1; ++i)
    {
        // 开始找图中到源点最近的点
        int tmp = INF;
        for (int j = 0; j < g.v; ++j)
        {
            if (!visit[j] && dist[j] < tmp)
            {
                u   = j;
                tmp = dist[j];
            }
        }
        // 新找到的到源点最近的
        // 这也是Dj跟Prim算法的区别
        // Dj是找到源点最近的点
        // Prim算法是找到u集合中所有点最近的点
        visit[u] = 1;
        // visit集合中新增了点 也就意味着图中其他点到源点的最短距离可能发生了变化
        // 源点->x点=源点->y点->x点
        for (int j = 0; j < g.v; ++j)
        {
            if (!visit[j] && (dist[u] + g.edges[u][j] < dist[j]))
            {
                // j->源点的最短距离发生了变化
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}

void traceBack(int path[], int i, int j)
{
    if (j == -1) return;
    traceBack(path, i, path[j]);
    std::cout << "j=" << j << " ";
}

int main(int argc, char** argv)
{
    MGraph g;
    // 顶点数
    g.v = 5;
    // 边数
    g.e = 14;
    for (int i = 0; i < g.v; ++i)
    {
        for (int j = 0; j < g.v; ++j)
        {
            // 邻接矩阵
            g.edges[i][j] = edgesW[i][j];
        }
    }
    int dist[MAX_SZ], path[MAX_SZ];
    Dijkstra(g, 0, dist, path);
    // 从顶点0到顶点4的最短路径
    traceBack(path, 0, 4);
    return 0;
}