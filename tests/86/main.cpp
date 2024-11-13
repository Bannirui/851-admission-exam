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

// 顶点
typedef struct VxNode
{
  int no;
} VexNode;

// 图
typedef struct MGraph
{
  int edges[MAX_SZ][MAX_SZ];
  int v, e;
  VexNode vex[MAX_SZ];
} MGraph;

// 矩阵 图中边
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
 * @param start 选定的出发点
 * @param sum 以v为出发点的最小生成树的路径结果
 */
void Prim(MGraph g, int start, int &sum)
{
  // u 集合 初始时u是空的
  // dist[i]语义是集合u到v中v[i]的距离是最短的
  int u[MAX_SZ], dist[MAX_SZ], tmp;

  for(int i=0;i<g.v;++i)
  {
    // 此时u中还是空的 准备把start加到u中 准备好v中所有结点到start的距离
    dist[i]=g.edges[start][i];
    // 初始化u 开始时u中是空的
    u[i]=0;
  }
  // 先把v点放到u中
  // 最终结果是最小生成树 特点是有n个结点 n-1条边 因此总共经过n轮遍历
  u[start]=1;
  std::cout<<"最小生成树的顶点为"<<start<<" ";

  // u中已经放好了一个结点 还剩n-1个结点要放
	for(int i=0;i<g.v-1;++i)
  {
    // v中结点到u中结点距离最短的距离
		int min=INF;
    // 从集合v中找到一个跟集合u中最近的点 放到集合u中
		for(int j=0;j<g.v;++j)
    {
      // 结点不是在u中就是在v中 不在u中就一定在v中
			if(!u[j] && dist[j]<min)
      {
				min=dist[j];
				tmp=j;
			}
    }
    // 在v中找到了一个结点tmp 它到u中结点的距离是最短的 是min
		u[tmp]=1;
    std::cout<<tmp<<" ";
		sum+=min;
    // u中有新增的结点tmp了 意味着v到u最短距离有更新
		for(int j=0;j<g.v;++j)
    {
			if(!u[j] && dist[j]>g.edges[tmp][j])
      {
				dist[j]=g.edges[tmp][j];
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