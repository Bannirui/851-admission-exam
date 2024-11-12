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

typedef struct VxNode
{
  int no;
} VexNode;

typedef struct MGraph
{
  int edges[MAX_SZ][MAX_SZ];
  int v, e;
  VexNode vex[MAX_SZ];
} MGraph;

// 矩阵 图中顶点到
int edgesW[5][5] =
{
  INF, 5, 1, 2, INF,
  5, INF, 4, INF, 4,
  1, 3, INF, 6, 2,
  2, INF, 6, INF, 3,
  INF, 4, 2, 3, INF
};

/**
 * 最小生成树
 * 目的是从图中n个结点找到n-1个边形成生成树 保证所有边的权重和最小
 * 创建两个集合u和v
 * u中是选好做生成树的结点
 * v中是候选结点
 * 初始时所有结点都在v中 然后每一轮都从v中找到一个点 它到u中点的距离最小 把它从v中挪到u中
 * 直到v中所有结点都到了u中结束
 * @param g 图
 * @param v 选定的出发点
 * @param sum 以v为出发点的最小生成树的路径结果
 */
void Prim(MGraph g, int v, int &sum)
{
  // visit 用于标识顶点被访问过 1表示被访问过 0表示还没被访问
  // u u集合
  int visit[MAX_SZ], dist[MAX_SZ], u;

  for(int i=0;i<g.v;++i)
  {
    // 点v到各个点的距离
    dist[i]=g.edges[v][i];
    // 初始化点都没被访问
    visit[i]=0;
  }
  // 标记顶点v被访问过了
  visit[v]=1;
  std::cout<<"最小生成树的顶点为"<<v<<" ";

  // 总共n个顶点 出发点已经确定好 剩下来n-1个顶点
	for(int i=0;i<g.v-1;++i)
  {
		int min=INF;
		for(int j=0;j<g.v;++j)
    {
			if(!visit[j] && dist[j]<min)
      {
				min=dist[j];
				u=j;
			}
    }
    // 找到了距离v最近的点各距离 v->u
		visit[u]=1;
    std::cout<<u<<" ";
		sum+=min;
    // 重新初始化距离表 记录v->x的距离
		for(int j=0;j<g.v;++j)
    {
      // v->j
      // v->u->j
			if(!visit[j] && dist[j]>g.edges[u][j])
      {
				dist[j]=g.edges[u][j];
      }
    }
	}
  std::cout<<std::endl;
  std::cout<<"最小生成树路径值是"<<sum<<std::endl;
}

int main(int argc, char** argv)
{
  // 实例化图
  MGraph g;
  int sum=0;
  g.e=8;
  g.v=5;
  // 初始化邻边 即权值
  for(int i=0;i<g.v;++i)
  {
    for(int j=0;j<g.v;++j)
    {
      g.edges[i][j]=edgesW[i][j];
    }
  }
  // Prim算法初始的时候没有结点 可以从任意点开始
  Prim(g, 0, sum);
  return 0;
}