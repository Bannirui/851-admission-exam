#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

#define maxsize 1024
#define INF 0x3f3f3f3f

typedef struct MGraph
{
	// 顶点数量
	int n;
	// 顶点间邻边的距离
	int edges[][maxsize];
} MGraph;

/**
 * 有两个顶点集合S和T
 * 集合S中存放已经找到最短路径的顶点
 * 集合T中存放图中剩余顶点
 * 初始状态时 集合S中只包含原点v0 然后不断从集合T中选取到顶点v0路径长度最短的顶点vu并入到集合S中
 * 集合S每入一个新的几点vu 都要修改顶点v0到集合T中顶点最短路径的长度
 * 不断重复这个过程 直到集合T中的顶点全部入到集合S中
 * @param dist 记录v点到其余顶点的最短路径长度
 * @param path 记录v点到其余顶点的最短路径
 */
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxsize];
	int min, i, j, u;
	// 数组初始化
	for (i = 0; i < g.n; ++i)
	{
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF) path[i] = v;
		else path[i] = -1;
	}
	set[v] = 1;
	path[v] = -1;
	// 初始化结束 开始执行操作
	for (i = 0; i < g.n - 1; i++)
	{
		min = INF;
		// 每次从剩余顶点中选出一个 通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的
		for (j = 0; j < g.n; ++j)
		{
			if (set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
			// 将选出来的顶点放到最短路径中
			set[u] = 1;
			// 以刚并入的顶点作为中间点 对所有通往剩余顶点的路径进行检查
			for (j = 0; j < g.n; ++j)
			{
				/**
				 * 判断顶点u的加入是否会出现通往顶点j的更短路径
				 * 如果出现则改变原来的最短路径及长度
				 * 否则什么都不做
				 */
				if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	return 0;
}