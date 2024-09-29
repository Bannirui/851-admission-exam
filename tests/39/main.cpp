#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20

char VName[5] = { 'A', 'B', 'C', 'D', 'E' };

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
void createGraph(AGraph*& G)
{
	G = (AGraph*)malloc(sizeof(AGraph));
	G->n = 5;
	G->e = 7;
	for (int i = 0; i <= G->n; i++)
	{
		G->adjlist[i].data = VName[i];
		G->adjlist[i].first = nullptr;
	}
	ArcNode* a1, * b1, * c1, * a2, * b2, * a3, * a4;
	a1 = (ArcNode*)malloc(sizeof(ArcNode));
	a1->adjvex = 1;
	b1 = (ArcNode*)malloc(sizeof(ArcNode));
	b1->adjvex = 3;
	c1 = (ArcNode*)malloc(sizeof(ArcNode));
	c1->adjvex = 4;
	G->adjlist[0].first = a1;
	a1->next = b1;
	b1->next = c1;
	c1->next = nullptr;
	a2 = (ArcNode*)malloc(sizeof(ArcNode));
	a2->adjvex = 4;
	b2 = (ArcNode*)malloc(sizeof(ArcNode));
	b2->adjvex = 2;
	G->adjlist[1].first = a2;
	a2->next = b2;
	b2->next = nullptr;
	a3 = (ArcNode*)malloc(sizeof(ArcNode));
	a3->adjvex = 0;
	G->adjlist[2].first = a3;
	a3->next = nullptr;
	a4 = (ArcNode*)malloc(sizeof(ArcNode));
	a4->adjvex = 2;
	G->adjlist[3].first = a4;
	a4->next = nullptr;
}
int dfs_visit[maxSize];
int bfs_visit[maxSize];
void DFS(AGraph* G, int v)
{
	ArcNode* s;
	dfs_visit[v] = 1;
	std::cout << "当前访问图结点的值为 " << G->adjlist[v].data << std::endl;
	s = G->adjlist[v].first;
	while (s != nullptr)
	{
		if (dfs_visit[s->adjvex] == 0)
		{
			DFS(G, s->adjvex);
		}
		s = s->next;
	}
}
void BFS(AGraph* G, int v)
{
	ArcNode* s;
	int queue[maxSize], front = 0, rear = 0;
	int j;
	bfs_visit[v] = 1;
	std::cout << "当前访问的结点的值为" << G->adjlist[v].data << std::endl;
	rear = (rear + 1) % maxSize;
	queue[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % maxSize;
		j = queue[front];
		s = G->adjlist[j].first;
		while (s != NULL)
		{
			if (bfs_visit[s->adjvex] == 0)
			{
				bfs_visit[s->adjvex] = 1;
				std::cout << "当前访问的值为" << G->adjlist[s->adjvex].data << std::endl;
				rear = (rear + 1) % maxSize;
				queue[rear] = s->adjvex;
			}
			s = s->next;
		}
	}
}
int main(int argc, char** argv)
{
	AGraph* g;
	createGraph(g);
	std::cout << "开始对图进行dfs" << std::endl;
	DFS(g, 0);
	std::cout << "开始对图进行bfs" << std::endl;
	BFS(g, 0);
	return 0;
}