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
	std::cout << "input  vertex number: ";
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
	// 初始化边的权重
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
	// 根据输入进行初始化边的权重值
	for (int i = 0; i < mEdgNum; i++)
	{
		// 读取边的起始顶点 结束顶点 权重值
		std::cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();
		std::cin >> weight;
		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			std::cout << "input error: invalid edge" << std::endl;
			return;
		}
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
	// prim最小树的索引 prims数组的索引
	int index = 0;
	// prims最小树的结果数组
	char prims[MAX];
	// 顶点间边的权重值
	int weights[MAX];
	// 第一个数是start顶点
	prims[index++] = mVexs[start];
	// 初始化 第start个顶点到第i个顶点的权重
	for (int i = 0; i < mVexNum; i++)
	{
		if (i == start) weights[i] = 0;
		else weights[i] = mMatrix[start][i];
	}
	for (int i = 0; i < mVexNum; i++)
	{
		// 从start开始的 不需要再对第start个顶点进行处理
		if (i == start)
			continue;
		j = 0;
		k = 0;
		min = INF;
		// 在未被加入到最小生成树的顶点中 找出权重值最小的顶点
		while (j < mVexNum)
		{
			// 第j个节点已经排序过 加入到了最小生成树中
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}
		// 经过上面的处理 在未被加入到最小生成树的顶点中 权重值最小的顶点是k 把顶点k加到最小生成树的结果数组中
		prims[index++] = mVexs[k];
		// 将k顶点的权重值标记为0 标识k顶点已经排序过了 加到了结果中
		weights[k] = 0;
		// 当顶点k被加入到了最小生成树后 更新其他顶点权重值
		for (j = 0; j < mVexNum; j++)
		{
			// 当节点j没有被处理 并且需要更新时才被更新
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
	std::cout << std::endl;
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
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int matrix[][9] = {
		{ 0, 12, INF, INF, INF, 16, 14 },
		{ 12, 9, 10, INF, INF, 7, INF },
		{ INF, 10, 0, 3, 5, 6, INF },
		{ INF, INF, 3, 0, 4, INF, INF },
		{ 16, 7, 6, INF, 2, 0, 9 },
		{ 14, INF, INF, 8, 9, 0 }
	};
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	MatrixUDG* pG;
	pG = new MatrixUDG(vexs, vlen, matrix);
	pG->print();
	pG->DFS();
	pG->BFS();
	pG->prim(0);
	return 0;
}