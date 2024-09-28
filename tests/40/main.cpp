#include <iostream>

#define maxSize 20
#define INF 1000

char VName[5] = { 'A', 'B', 'C', 'D', 'E' };
int weight[5][5] = { INF, 3, 2, 4, 1,
					 3, INF, 5, INF, 6, 2,
					 5, INF, 2, INF, 4,
					 INF, 2, INF, INF, 1,
					 6, INF, INF, INF
};
int weight2[4][4] = { 0, 5, INF, 7,
					  INF, 0, 4, 2,
					  3, 3, 0, 2,
					  INF, INF, 1, 0
};
int set[maxSize];
typedef struct
{
	int no;
	char data;
} Vnode;
typedef struct
{
	int edgeW[maxSize][maxSize];
	int n, e;
	Vnode vex[maxSize];
} MGraph;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* next;
} ArcNode;
typedef struct VNode
{
	char data;
	ArcNode* first;
} VNode;
typedef struct AGraph
{
	VNode adjlist[maxSize];
	int n, e;
} AGraph;
void createMGraph(MGraph& g)
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
}
void createMGraph2(MGraph& g)
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
			g.edgeW[i][j] = weight2[i][j];
		}
	}
}
void createAGraph(AGraph*& g)
{
	g = (AGraph*)malloc(sizeof(AGraph));
	g->n = 5;
	g->e = 7;
	for (int i = 0; i < g->n; ++i)
	{
		g->adjlist[i].data = VName[i];
		g->adjlist[i].first = nullptr;
	}
	ArcNode* a1, * b1, * c1, * a2, * b2, * a3, * a4;
	a1 = (ArcNode*)malloc(sizeof(ArcNode));
	b1 = (ArcNode*)malloc(sizeof(ArcNode));
	c1 = (ArcNode*)malloc(sizeof(ArcNode));
	a2 = (ArcNode*)malloc(sizeof(ArcNode));
	b2 = (ArcNode*)malloc(sizeof(ArcNode));
	a3 = (ArcNode*)malloc(sizeof(ArcNode));
	a4 = (ArcNode*)malloc(sizeof(ArcNode));

	a1->adjvex = 1;
	b1->adjvex = 3;
	c1->adjvex = 4;
	g->adjlist[0].first = a1;
	a1->next = b1;
	b1->next = c1;
	c1->next = nullptr;

	a2->adjvex = 4;
	b2->adjvex = 2;
	g->adjlist[1].first = a2;
	a2->next = b2;
	b2->next = nullptr;

	a3->adjvex = 0;
	g->adjlist[2].first = a3;
	a3->next = nullptr;

	a4->adjvex = 2;
	g->adjlist[3].first = a4;
	a4->next = nullptr;
}
void DFS(AGraph* g, int v)
{

}
int main(int argc, char** argv)
{
	std::cout << "hello world" << std::endl;
	return 0;
}