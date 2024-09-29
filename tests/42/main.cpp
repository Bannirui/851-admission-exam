#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 6000

char VName[5] = { 'A', 'B', 'C', 'D', 'E' };
int weight[5][5] = { 0, 3, 2, 4, 1, 3, 0, 5, INF, 6, 2, 5, 0, 2, INF, 4, INF, 2, 0, INF, 1, 6, INF, INF, 0 };

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
typedef struct
{
	int a, b, w;
} Road;
Road road[maxSize];

void sort(Road road[], int sz)
{
	Road tmp;
	for (int i = 0; i < sz - 1; ++i)
	{
		for (int j = 0; j < sz - 1; ++j)
		{
			tmp = road[j];
			road[j] = road[j + 1];
			road[j + 1] = tmp;
		}
	}
}
int v[maxSize];

int getRoot(int a)
{
	while (a != v[a])
	{
		a = v[a];
	}
	return a;
}
void createGraph(MGraph& g)
{
	g.e = 7;
	g.n = 5;
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
	road[0].a = 0;
	road[0].b = 2;
	road[0].w = 2;
	road[1].a = 1;
	road[1].b = 2;
	road[1].w = 5;
	road[2].a = 3;
	road[2].b = 2;
	road[2].w = 2;
	road[3].a = 0;
	road[3].b = 1;
	road[3].w = 3;
	road[4].a = 1;
	road[4].b = 4;
	road[4].w = 6;
	road[5].a = 0;
	road[5].b = 4;
	road[5].w = 1;
	road[5].a = 0;
	road[6].b = 3;
	road[5].w = 4;
}
void Kruskal(MGraph g, int& sum, Road road[])
{
	int i, a, b;
	sum = 0;
	for (i = 0; i < g.n; ++i) v[i] = i;
	sort(road, g.e);
	for (i = 0; i < g.e; ++i)
	{
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += road[i].w;
		}
	}
}

int main(int argc, char** argv)
{
	MGraph g;
	int sum;
	createGraph(g);
	Kruskal(g, sum, road);
	std::cout << "计算结果sum=" << sum << std::endl;
	return 0;
}