//
// Created by dingrui on 2024/7/4.
//

#ifndef INC_851_ADMISSION_EXAM_TESTS_08_MATRIXUDG_H_
#define INC_851_ADMISSION_EXAM_TESTS_08_MATRIXUDG_H_

class MatrixUDG
{
#define MAX 100
#define INF (~(0x1<<31))
 private:
	// 顶点集合
	char mVexs[MAX];
	// 顶点数
	int mVexNum;
	// 边数
	int mEdgNum;
	// 邻接矩阵
	int mMatrix[MAX][MAX];

 public:
	// 创建图
	MatrixUDG();
	MatrixUDG(char vexs[], int vlen, int matrix[][9]);
	~MatrixUDG();

	// dfs
	void DFS();
	// bfs
	void BFS();
	/**
	 * 从start开始生成最小生成树
	 * @param start 从图中的第start个元素开始 生成最小树
	 */
	void prim(int start);
	// 打印矩阵队列图
	void print();

 private:
	// 读取一个输入字符
	char readChar();
	// 返回ch在mMatrix矩阵中的位置
	int getPosition(char ch);
	// 返回顶点v的第一个邻接顶点的索引 失败则返回-1
	int firstVertex(int v);
	// 返回顶点v相对于w的下一个邻接顶点的索引 失败则返回-1
	int nextVertex(int v, int w);
	// dfs遍历图
	void dfs(int i, int* visited);
};

#endif //INC_851_ADMISSION_EXAM_TESTS_08_MATRIXUDG_H_
