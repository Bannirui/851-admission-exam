#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

char VName[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int weight[7][7] = { 0, 4, 6, 6, INF, INF, INF,
					 4, 0, 1, INF, 7, INF, INF,
					 6, 1, 0, 2, 6, 4, INF,
					 6, INF, 2, 0, INF, 5, INF,
					 INF, 7, 6, INF, 0, 1, 6,
					 INF, INF, 4, 5, 1, 0, 8,
					 INF, INF, INF, INF, 6, 8, 0
};

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
	g.e = 12;
	g.n = 7;
	for (int i = 0; i < g.n; ++i)
	{
		g.vex[i].data = VName[i];
		g.vex[i].no = i;
	}
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j < g.n; j++)
		{
			g.edgeW[i][j] = weight[i][j];
		}
	}
}
void getPath(int path[], int a)
{
	int stack[maxSize], top = -1;
	while (path[a] != -1)
	{
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1)
	{
		std::cout << stack[top--] << "-->";
	}
	std::cout << std::endl;
}
void traceBack(int path[], int j)
{
	if (j == -1) return;
	traceBack(path, path[j]);
	std::cout << j << " ";
}
void Dijikstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxSize];
	int min, i, j, u;
	for (i = 0; i < g.n; ++i)
	{
		dist[i] = g.edgeW[v][i];
		set[i] = 0;
		if (g.edgeW[v][i] < INF) path[i] = v;
		else path[i] = -1;
	}
	set[v] = 1;
	path[v] = -1;
	for (i = 0; i < g.n - 1; ++i)
	{
		min = INF;
		for (j = 0; j < g.n; ++j)
		{
			u = j;
			min = dist[j];
		}
		set[u] = 1;
		for (j = 0; j < g.n; ++j)
		{
			if (set[j] == 0 && dist[u] + g.edgeW[u][j] < dist[j])
			{
				dist[j] = dist[u] + g.edgeW[u][j];
				path[j] = u;
			}
		}
	}
}
int main(int argc, char** argv)
{
	std::cout<<"狄杰斯特拉算法"<<std::endl;
	MGraph g;
	int sum, dist[maxSize], path[maxSize];
	createGraph(g);
	Dijikstra(g, 0, dist, path);
	getPath(path, 5);
	traceBack(path, 5);
	return 0;
}