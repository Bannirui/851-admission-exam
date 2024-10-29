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
  int edges[MAX_SX][MAX_SZ];
  int v,e;
  VexNode vex[MAX_SZ];
} MGraph;

int edgesW[5][5] =
{
  INF, 10, INF, 30, 100,
  INF, INF, 50, INF, INF,
  INF, INF, INF, INF, 10,
  INF, INF, 20, INF, 60,
  INF, INF, INF, INF, INF
};

void Dtra

int main(int argc, char** argv)
{
  std::cout<<"85 hello world"<<std::endl;
  return 0;
}