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
  // 图的邻接矩
  int edges[MAX_SZ][MAX_SZ];
  VexNode vex[MAX_SZ];
  // 顶点数量和边的数量
  int v,e;
} MGraph;

// 顶点的邻接矩阵 INF表示两点没有连通
int edgesW[9][9] =
{
  0, 4, INF, INF, INF, INF, INF, 8, INF,
  4, 0, 8, INF, INF, INF, INF, 11, INF,
  INF, 8, 0, 7, INF, 4, INF, INF, 2,
  INF, INF, 7, 0, 9, 14, INF, INF, INF,
  INF, INF, INF, 9, 0, 10, INF, INF, INF,
  INF, INF, 4, 14, 10, 0, 2, INF, INF,
  INF, INF, INF, INF, INF, 2, 0, 1, 6,
  8, 11, INF, INF, INF, INF, 1, 0, 7,
  INF, INF, 2, INF, INF, INF, 6, 7, 0,
};

/**
 * @param v 源点
 * @param dist 用于缓存v到其他顶点的距离 dist[i]的语义是v到i的距离
 * @param path 用于缓存路径 path[i]的语义是
 */
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
  // 标识顶点是否访问过 0表示还没访问过 1表示已经访问过
  int visit[MAX_SZ];
  // 用来缓存到v点最近的是哪个点
  int u;
  // 遍历顶点 当前源点v可以到达的所有顶点
  for(int i=0;i<g.v;++i)
  {
    dist[i]=g.edges[v][i];
    visit[i]=0;
    if(dist[i]<INF)
    {
      // 说明v到i可以直达
      path[i]=v;
    }
    else
    {
      // 顶点v到i不可直达
      path[i]=-1;
    }
  }
  // 标识顶点v被访问过
  visit[v]=1;
  for(int i=0;i<g.v-1;++i)
  {
    // 记录距离v点最近的点是多远
    int tmp=INF;
    for(int j=0;j<g.v;++j)
    {
      if(!visit[j] && dist[j]<tmp)
      {
        // 缓存到v点距离最近的点
        u=j;
        tmp=dist[j];
      }
    }
    // 标识
    visit[u]=1;
    for(int j=0;j<g.v;++j)
    {
      if(!visit[j] && (dist[j]>g.edges[u][j]+dist[u]))
      {
        dist[j]=g.edges[u][j]+dist[u];
        path[j]=u;
      }
    }
  }
}

void traceBack(int path[], int i, int j)
{
  if(j==-1) return;
  traceBack(path, i, path[j]);
  std::cout<<"j="<<j<<" ";
}

int main(int argc, char** argv)
{
  MGraph g;
  // 顶点数
  g.v=9;
  // 边数
  g.e=14;
  for(int i=0;i<g.v;++i)
  {
    for(int j=0;j<g.v;++j)
    {
      // 邻接矩阵
      g.edges[i][j]=edgesW[i][j];
    }
  }
  int dist[MAX_SZ],path[MAX_SZ];
  Dijkstra(g, 0, dist, path);
  // 从顶点0到顶点4的最短路径
  traceBack(path, 0 ,4);
  return 0;
}