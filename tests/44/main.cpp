#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

char VName[4] = { 'A', 'B', 'C', 'D' };
int weight[4][4] = { 0, 5, INF, 7, INF, 0, 4, 2, 3, 3, 0, 2, INF, INF, 1, 0 };

typedef struct
{
	int no;
	char data;
} VNode;

typedef struct
{
	int edgeW[maxSize][maxSize];
	int n, e;
	VNode vex[maxSize];
} MGraph;

void createGraph(MGraph& g)
{
	g.e = 8;
	g.n = 4;

	for (int i = 0; i < g.n; ++i)
	{
		g.vex[i].data = VName[i];
		g.vex[i].no = i;
	}
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j < g.n; ++j)
		{
			g.edgeW[i][j] = weight[i][j];
		}
	}
}

void getPath(int u, int v, int path[][maxSize], int A[][maxSize])
{
	if (A[u][v] == INF) std::cout << "No Road" << std::endl;
	else
	{
		if (path[u][v] == -1) std::cout << "<" << u << ", " << ">";
		else
		{
			int mid = path[u][v];
			getPath(u, mid, path, A);
			getPath(mid, v, path, A);
		}
	}
}

void Floyd(MGraph g, int path[][maxSize], int A[][maxSize])
{
	int i, j, k;
	for (i = 0; i < g.n; ++i)
	{
		for (j = 0; j < g.n; ++j)
		{
			path[i][j] = -1;
			A[i][j] = g.edgeW[i][j];
		}
	}
	for (k = 0; k < g.n; ++k)
	{
		for (i = 0; i < g.n; ++i)
		{
			for (j = 0; j < g.n; ++j)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::cout<<"弗洛依德算法"<<std::endl;
	MGraph g;
	int sum, A[maxSize][maxSize], path[maxSize][maxSize];
	createGraph(g);
	Floyd(g, path, A);
	getPath(1, 0, path, A);
	return 0;
}