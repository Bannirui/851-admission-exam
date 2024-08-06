//
// Created by dingrui on 2024/7/4.
//

#include <iostream>

#include "MatrixUDG.h"

MatrixUDG::MatrixUDG()
{
	char c1, c2;
	int i, j, weight, p1, p2;
	// 顶点数和边数
	std::cout << "input vertex number: ";
	std::cin >> mVexNum;
	std::cout << "input edge number: ";
	std::cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum - 1))))
	{
		std::cout << "input error: invalid parameters" << std::endl;
		return;
	}
	// 初始化顶点
	for (i = 0; i < mVexNum; i++)
	{
		std::cout << "vertex(" << i << "): ";
		mVexs[i] = readChar();
	}
	// 初始化边的权重 自己到自己的距离是0 其余顶点间的距离都初始化成最大值 然后等待输入的值来覆盖
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
		{
			if (i == j)
				mMatrix[i][j] = 0;
			else
				mMatrix[i][j] = INF;
		}
	}
	// 根据输入覆盖上面初始化的值
	for (int i = 0; i < mEdgNum; i++)
	{
		// 读取边的起始顶点 结束顶点 权重值
		std::cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();
		// 顶点c1->c2这条边的权重值
		std::cin >> weight;
		// 顶点脚标位置
		p1 = getPosition(c1);
		// 顶点脚标位置
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			std::cout << "input error: invalid edge" << std::endl;
			return;
		}
		// 邻接矩阵中两个顶点间的距离
		mMatrix[p1][p2] = weight;
		mMatrix[p2][p1] = weight;
	}
}
MatrixUDG::MatrixUDG(char* vexs, int vlen, int (* matrix)[9])
{
	int i, j;
	// 初始化顶点数和边数
	mVexNum = vlen;
	// 初始化顶点
	for (int i = 0; i < mVexNum; i++)
		mVexs[i] = vexs[i];
	// 初始化边
	for (i = 0; i < mVexNum; i++)
		for (j = 0; j < mVexNum; j++)
			mMatrix[i][j] = matrix[i][j];
	// 统计边的数量
	for (i = 0; i < mVexNum; i++)
		for (j = 0; j < mVexNum; j++)
			if (i != j && mMatrix[i][j] != INF)
				mEdgNum++;
	mEdgNum /= 2;
}
MatrixUDG::~MatrixUDG()
{
}
void MatrixUDG::DFS()
{
	int i;
	int visited[MAX];
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;
	std::cout << "DFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
			dfs(i, visited);
	}
	std::cout << std::endl;
}
void MatrixUDG::BFS()
{
	int head = 0;
	int rear = 0;
	int queue[MAX];
	int visited[MAX];
	int i, j, k;
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;
	std::cout << "BFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			std::cout << mVexs[i] << " ";
			queue[rear++] = i;
		}
		while (head != rear)
		{
			j = queue[head++];
			for (k = firstVertex(j); k >= 0; k = nextVertex(j, k))
			{
				if (!visited[k])
				{
					visited[k] = 1;
					std::cout << mVexs[k] << " ";
					queue[rear++] = k;
				}
			}
		}
	}
	std::cout << std::endl;
}
void MatrixUDG::prim(int start)
{
	int min, i, j, k, m, n, sum;
	// prims最小树的结果数组 形式如A->B->C->...这样的一个数组
	char prims[MAX];
	/**
	 * 从start出发到各个顶点的距离
	 * 0有2个语义
	 * <ul>
	 *   <li>顶点自己到自己的距离是0</li>
	 *   <li>标识两个顶点已经处理过 加到了结果中</li>
	 * </ul>
	 */
	int weights[MAX];
	// prim最小树的索引 prims数组的索引
	int index = 0;
	// 整棵数的起点从顶点start开始
	prims[index++] = mVexs[start];
	// 遍历所有顶点 缓存从顶点start到每一个顶点的距离
	for (int i = 0; i < mVexNum; i++)
	{
		// 自己到自己的距离是0 从邻接表中读取start->i的距离
		if (i == start) weights[i] = 0;
		else weights[i] = mMatrix[start][i];
	}
	// 轮询所有顶点 每次处理的都是从轮询到的顶点为出发点 找距离最近的顶点
	for (int i = 0; i < mVexNum; i++)
	{
		// start是起始顶点 已经放到了结果中了 不需要对start进行处理
		if (i == start) continue;
		j = 0;
		// k缓存最小距离的顶点编号 min缓存中最小距离
		k = 0;
		min = INF;
		// 从所有顶点中找到距离最小的目标顶点
		while (j < mVexNum)
		{
			// 找到了最小距离的候选顶点 缓存起来
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}
		// start->k是找到的最小的距离
		prims[index++] = mVexs[k];
		// 置0标识顶点k已经处理好了放在了结果中
		weights[k] = 0;
		// 当顶点k被加入到了最小生成树后 更新其他顶点权重值
		for (j = 0; j < mVexNum; j++)
		{
			// 下一轮的距离 上一轮从start->k 下一轮从k->?
			if (weights[j] != 0 && mMatrix[k][j] < weights[j])
				weights[j] = mMatrix[k][j];
		}
	}
	// 计算最小生成树的权重值
	sum = 0;
	for (int i = 1; i < index; i++)
	{
		min = INF;
		// 获取prims[i]在mMatrix中的位置
		n = getPosition(prims[i]);
		// 在vexs[0...i]中找到j的权重值最小的顶点
		for (j = 0; j < i; j++)
		{
			m = getPosition(prims[j]);
			if (mMatrix[m][n] < min)
				min = mMatrix[m][n];
		}
		sum += min;
	}
	// 打印
	std::cout << "PRIM(" << mVexs[start] << ")=" << sum << ": ";
	for (i = 0; i < index; i++)
		std::cout << prims[i] << " ";
	std::cout << "\n";
}
void MatrixUDG::print()
{
	int i, j;
	std::cout << "Matrix Graph:\n";
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
			std::cout << mMatrix[i][j] << " ";
		std::cout << "\n";
	}
}
char MatrixUDG::readChar()
{
	char ch;
	do
	{
		std::cin >> ch;
	} while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));
	return ch;
}
int MatrixUDG::getPosition(char ch)
{
	int i;
	for (i = 0; i < mVexNum; i++)
		if (mVexs[i] == ch)
			return i;
	return -1;
}
int MatrixUDG::firstVertex(int v)
{
	int i;
	if (v < 0 || v > (mVexNum - 1))
		return -1;
	for (i = 0; i < mVexNum; i++)
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;
	return -1;
}
int MatrixUDG::nextVertex(int v, int w)
{
	int i;
	if (v <= 0 || v > (mVexNum - 1) || w < 0 || w > (mVexNum - 1))
		return -1;
	for (i = w + 1; i < mVexNum; i++)
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;
	return -1;
}
void MatrixUDG::dfs(int i, int* visited)
{
	int w;
	visited[i] = 1;
	std::cout << mVexs[i] << " ";
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
	{
		if (!visited[w])
			dfs(w, visited);
	}
}

int main()
{
	// 顶点
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	// 邻边
	int matrix[][9] = {
		//A     B    C    D     E   F     G
		{ 0, 12, INF, INF, INF, 16, 14 }, // A
		{ 12, 0, 9, 10, INF, INF, 7 },//  B
		{ INF, 9, 0, 7, 5, 6, 8 },//  C
		{ INF, 9, 7, 0, 4, INF, INF },// D
		{ INF, INF, 5, 4, 0, INF, INF },// E
		{ 16, INF, 6, INF, INF, 0, INF },//  F
		{ 14, 7, 8, INF, INF, INF, 0 } //   G
	};
	// 顶点个数
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	MatrixUDG* pG;
	pG = new MatrixUDG(vexs, vlen, matrix);
//	pG->print();
//	pG->DFS();
//	pG->BFS();
	pG->prim(1);
	return 0;
}