#include <string.h>
#include <iostream>

#ifdef __APPLE__
#include <limits>
#elif __linux__
#include <climits>
#endif

/**
 * 单源最短路径问题 使用Dijkstra算法进行求解
 * 使用的数据结构为连通带权图G(V,E)
 * 其中V标识所有结点集合 设置顶点集合S并不断地做贪心选择来扩充这一集合 当从源到顶点的最短路径长度已知时加入到集合S中
 * 初始时 S中仅含有源 u是G中的某一顶点 从源到u且只经过S中顶点的路称为从源到u的特殊路径 使用数组dist记录当前每个顶点所对应的最短特殊路径长度
 * Dijkstra算法每次从V-S中取出具有最短特殊路径长度是顶点u 添加到S中 再修改dist数组 直到S包含所有顶点为止
 * 此时统计dist数组中的总和即为源到其它各结点的路径长度和
 * 对所有候选结点进行Dijkstra算法求解最短路径和 最终取最小路径和的结点为最终求解结果
 * 实现时使用邻接矩阵(即二维数组c)存储图中的各个结点之间的距离 其中c[i][j]为结点i到结点j之间的距离
 * maxint表示两点不可直达
 * 使用数组candidate存储所有候选结点 candidateSize为候选结点数量
 * Dijkstra算法进行最短路径搜索 并返回其总和 初始化时dist数组为各顶点到源的距离 同时为在寻找结点只过滤其它候选结点 集合S初始中包含所有的候选结点 使用findBest依次遍历各结点的最短路径和 最终通过argmin函数找到具有最小的最短路径和的结点编号 返回编号
 * @param n
 * @param v 考察的顶点
 * @param dist 记录顶点v到各个顶点的特殊路径长度
 * @param prev
 * @param c 各个结点的邻接矩阵 保存了图中各顶点之间的距离
 * @param candidate
 * @param candidateSize 数组candidate的长度
 */
int Dijkstra(int n, int v, int dist[], int prev[], int** c, int candidate[], int candidateSize)
{
	// 标识顶点已经搜索过
	bool s[n + 1];
	// v结点到各顶点的最短路径长度
	int minLength = 0;
	// 初始化
	for (int i = 1; i < n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;
		// 两点不可直达
		if (dist[i] == INT_MAX) prev[i] = 0;
		else prev[i] = v;
	}
	dist[v] = 0;
	// 将候选点加入到集合S中 之后的最短路径搜索时将不再计算候选结点
	for (int i = 0; i < candidateSize; i++) s[candidate[i]] = true;
	// 单源最短路径搜索
	for (int i = 1; i < n; i++)
	{
		// 初始时为无穷大
		int tmp = INT_MAX;
		// u为具有最短特殊的顶点
		int u = v;
		for (int j = 1; j <= n; j++)
		{
			if (!s[j] && dist[j] < tmp)
			{
				u = j;
				tmp = dist[j];
			}
		}
		s[u] = true;
		minLength += dist[u];
		// 更新dist数组
		for (int j = 1; j <= n; j++)
		{
			if (!s[j] && c[u][j] < INT_MAX)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
	return minLength;
}

/**
 * 计算具有最小的最短路径和的结点和编号
 * 从一维数组中找到最小值的脚标
 * @param candidateLength 数组
 * @param candidateSize 数组长度
 */
int argmin(int candidateLength[], int candidateSize)
{
	int minIndex = 0;
	for (int i = 1; i < candidateSize; i++)
	{
		if (candidateLength[i] < candidateLength[minIndex])
		{
			minIndex = i;
		}
	}
	return minIndex;
}

/**
 * 依次遍历所有候选结点 计算其最短路径和 返回最短路径和的编号
 * @param n
 * @param candidate
 * @param candidateSize 一维数组candidate的长度
 * @param c 图的邻接矩阵 图中各顶点间的距离
 */
int findBest(int n, int candidate[], int candidateSize, int** c)
{
	int candidateLength[candidateSize];
	int dist[n + candidateSize + 1];
	int prev[n + candidateSize + 1];
	for (int i = 0; i < candidateSize; i++)
	{
		candidateLength[i] = Dijkstra(n + candidateSize, candidate[i], dist, prev, c, candidate, candidateSize);
	}
	return argmin(candidateLength, candidateSize);
}

int main(int argc, char** argv)
{
	std::cout << "hello world" << std::endl;
	return 0;
}