#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

typedef struct ArcNode {
  int adjvex;
  struct ArcNode *next;
} ArcNode;

typedef struct {
  char data;
  int count;
  ArcNode *first;
} VNode;

typedef struct {
  VNode adjlist[maxSize];
  int n, e;
} AGraph;

void createGraph(AGraph *&g) {
  g = (AGraph *)malloc(sizeof(AGraph));
  g->e = 11;
  g->n = 7;

  ArcNode *a1, *b1, *c1, *d1, *a2, *b2, *c2, *a3, *b3, *c3, *a4, *b4, *a5, *b5,
      *a6, *b6, *c6, *a7;
  a1 = (ArcNode *)malloc(sizeof(ArcNode));
  b1 = (ArcNode *)malloc(sizeof(ArcNode));
  c1 = (ArcNode *)malloc(sizeof(ArcNode));
  d1 = (ArcNode *)malloc(sizeof(ArcNode));

  a2 = (ArcNode *)malloc(sizeof(ArcNode));
  b2 = (ArcNode *)malloc(sizeof(ArcNode));
  c2 = (ArcNode *)malloc(sizeof(ArcNode));

  a3 = (ArcNode *)malloc(sizeof(ArcNode));
  b3 = (ArcNode *)malloc(sizeof(ArcNode));
  c3 = (ArcNode *)malloc(sizeof(ArcNode));

  a4 = (ArcNode *)malloc(sizeof(ArcNode));
  b4 = (ArcNode *)malloc(sizeof(ArcNode));

  a5 = (ArcNode *)malloc(sizeof(ArcNode));
  b5 = (ArcNode *)malloc(sizeof(ArcNode));

  a6 = (ArcNode *)malloc(sizeof(ArcNode));
  b6 = (ArcNode *)malloc(sizeof(ArcNode));
  c6 = (ArcNode *)malloc(sizeof(ArcNode));

  a7 = (ArcNode *)malloc(sizeof(ArcNode));

  a1->adjvex = 0;
  b1->adjvex = 1;
  c1->adjvex = 2;
  d1->adjvex = 3;

  a2->adjvex = 1;
  b2->adjvex = 4;
  c2->adjvex = 2;

  a3->adjvex = 2;
  b3->adjvex = 4;
  c3->adjvex = 5;

  a4->adjvex = 3;
  b4->adjvex = 5;

  a5->adjvex = 4;
  b5->adjvex = 6;

  a6->adjvex = 5;
  b6->adjvex = 4;
  c6->adjvex = 6;

  a7->adjvex = 6;

  g->adjlist[0].first = a1;
  g->adjlist[0].count = 0;
  g->adjlist[0].data = 'A';

  g->adjlist[1].first = a2;
  g->adjlist[1].count = 1;
  g->adjlist[1].data = 'B';

  g->adjlist[2].first = a3;
  g->adjlist[2].count = 2;
  g->adjlist[2].data = 'C';

  g->adjlist[3].first = a4;
  g->adjlist[3].count = 1;
  g->adjlist[3].data = 'D';

  g->adjlist[4].first = a5;
  g->adjlist[4].count = 3;
  g->adjlist[4].data = 'E';

  g->adjlist[5].first = a6;
  g->adjlist[5].count = 2;
  g->adjlist[5].data = 'F';

  g->adjlist[6].first = a7;
  g->adjlist[6].count = 2;
  g->adjlist[6].data = 'G';

  a1->next = b1;
  b1->next = c1;
  c1->next = d1;
  d1->next = NULL;

  a2->next = b2;
  b2->next = c2;
  c2->next = NULL;

  a3->next = b3;
  b3->next = c3;
  c3->next = NULL;

  a4->next = b4;
  b4->next = NULL;

  a5->next = b5;
  b5->next = NULL;

  a6->next = b6;
  b6->next = c6;
  c6->next = NULL;

  a7->next = NULL;
}

int topSort(AGraph *g) {
  int stack[maxSize], top = -1, n = 0;
  ArcNode *s;
  for (int i = 0; i < g->n; ++i) {
    if (g->adjlist[i].count == 0) {
      stack[++top] = i;
    }
  }
  while (top != -1) {
    int i = stack[top--];
    ++n;
    std::cout << i << " ";
    s = g->adjlist[i].first;
    while (s != NULL) {
      --(g->adjlist[s->adjvex].count);
      if (g->adjlist[s->adjvex].count == 0) {
        stack[++top] = s->adjvex;
      }
      s = s->next;
    }
  }
  if (n == g->n)
    return 1;
  return 0;
}

int main(int argc, char **argv) {
  AGraph *g;
  ArcNode *s;
  int sum, A[maxSize][maxSize], path[maxSize][maxSize];
  createGraph(g);
  std::cout << "&&" << topSort(g);
  for (int i = 0; i < 7; ++i) {
    s = g->adjlist[i].first;
    while (s != NULL) {
      std::cout << s->adjvex << " ";
      s = s->next;
    }
    std::cout << std::endl;
  }
  return 0;
}