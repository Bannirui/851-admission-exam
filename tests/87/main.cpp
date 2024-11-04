#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define MAX_SZ 20
#define INF 1000

typedef struct VexNode
{
  int no;
} VexNode;

typedef struct MGraph
{
  // 邻边 表示点到
  int edges[MAX_SZ][MAX_SZ];
  int v, e;
  VexNode vex[MAX_SZ];
} MGraph;

// 点到点距离 作为图中邻边
int edgesW[5][5]=
{
  INF, 5, 1, 2, INF,
  5, INF, 3, INF, 4,
  1, 3, INF, 6, 2,
  2, INF, 6, INF, 3,
  INF, 4, 2, 3, INF
};

typedef struct Road
{
  int a, b, w;
} Road;

Road road[MAX_SZ];
int v[MAX_SZ];

int getRoot(int a)
{
  while(a!=v[a])
  {
    a=v[a];
  }
  return a;
}

// 快排
void sort_w(Road road[], int lo, int hi)
{
  int i=lo, j=hi;
  Road tmp;
  // base
  if(lo<hi)
  {
    tmp=road[lo];
    while(i<j)
    {
      // 相对tmp 右边都是比tmp大的
      while(i<j && road[j].w>=tmp.w)
      {
        --j;
      }
      // 把比tmp小的挪到左边
      if(i<j)
      {
        road[i]=road[j];
        ++i;
      }
      // 相对tmp 左边都是比tmp小的
      while(i<j && road[i].w<tmp.w)
      {
        ++i;
      }
      // 把比tmp大的挪到右边
      if(i<j)
      {
        road[j]=road[i];
        --j;
      }
    }
    // 调整base到i
    road[i]=tmp;
    // 此时整个数组相对有序 i左边的都比i小 i右边都比i大 继续递归左边和右边
    sort_w(road, lo, i-1);
    sort_w(road, i+1, hi);
  }
}

void Kruskal(MGraph g, int &sum, Road road[])
{
  for(int i=0;i<g.v;++i)
  {
    v[i]=i;
  }
  sort_w(road, 0, g.e-1);
  for(int i=0;i<g.e;++i)
  {
    int a=getRoot(road[i].a);
    int b=getRoot(road[i].b);
    if(a!=b)
    {
      v[a]=b;
      sum+=road[i].w;
    }
  }
}

int main(int argc, char** argv)
{
  MGraph g;
  int sum=0, k=0;
  g.e=8;
  g.v=5;
  for(int i=0;i<g.v;++i)
  {
    for(int j=0;j<g.v;++j)
    {
      g.edges[i][j]=edgesW[i][j];
    }
  }

  for(int i=0;i<g.v;++i)
  {
    for(int j=i+1;j<g.v;++j)
    {
      if(g.edges[i][j]!=INF)
      {
        road[k].a=i;
        road[k].b=j;
        road[k].w=g.edges[i][j];
        ++k;
      }
    }
  }
  Kruskal(g, sum, road);
  std::cout<<"最小生成树的路径结果为"<<sum<<std::endl;
  return 0;
}