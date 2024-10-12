#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20

char VName[5] = {'A', 'B', 'C', 'D', 'E'};

typedef struct ArcNode {
  int adjvex;
  struct ArcNode *next;
} ArcNode;

typedef struct VNode {
  char data;
  ArcNode *first;
} VNode;

typedef struct AGraph {
  VNode adjlist[maxSize];
  int n, e;
} AGraph;

void createGrapj(AGraph *&G) {
  G = (AGraph *)malloc(sizeof(AGraph));
  G->n = 5;
  G->e = 7;
  for (int i = 0; i <= G->n; ++i) {
    G->adjlist[i].data = VName[i];
    G->adjlist[i].first = NULL;
  }
  ArcNode *a1, *b1, *c1, *d1, *a2, *b2, *c2, *a3, *b3, *c3, *a4, *b4, *a5, *b5;
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

  a1->adjvex = 1;
  b1->adjvex = 2;
  c1->adjvex = 3;
  d1->adjvex = 4;
  G->adjlist[0].first = a1;
  a1->next = b1;
  b1->next = c1;
  c1->next = d1;
  d1->next = NULL;

  a2->adjvex = 0;
  b2->adjvex = 2;
  c2->adjvex = 4;
  G->adjlist[1].first = a2;
  a2->next = b2;
  b2->next = c2;
  c2->next = NULL;

  a3->adjvex = 1;
  b3->adjvex = 0;
  c3->adjvex = 3;
  G->adjlist[2].first = a3;
  a3->next = b3;
  b3->next = c3;
  c3->next = NULL;

  a4->adjvex = 0;
  b4->adjvex = 2;
  G->adjlist[3].first = a4;
  a4->next = b4;
  b4->next = NULL;

  a5->adjvex = 0;
  b5->adjvex = 1;
  G->adjlist[4].first = a5;
  a5->next = b5;
  b5->next = NULL;
}

int visit