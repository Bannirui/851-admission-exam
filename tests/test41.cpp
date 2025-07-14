#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 6000

char VName[5]     = {'A', 'B', 'C', 'D', 'E'};
int  weight[5][5] = {{0, 3, 2, 4, 1}, {3, 0, 5, INF, 6}, {2, 5, 0, 2, INF}, {4, INF, 2, 0, INF}, {1, 6, INF, INF, 0}};

typedef struct
{
    int  no;
    char data;
} VNode;
typedef struct
{
    int   edgeW[maxSize][maxSize];
    int   n, e;
    VNode vex[maxSize];
} MGraph;
void createGraph(MGraph& g)
{
    g.e = 7;
    g.n = 5;
    for (int i = 0; i < g.n; ++i)
    {
        g.vex[i].data = VName[i];
        g.vex[i].no   = i;
    }
    for (int i = 0; i < g.n; ++i)
    {
        for (int j = 0; j < g.n; ++j) g.edgeW[i][j] = weight[i][j];
    }
}
void prim(MGraph g, int v, int& sum)
{
    int lowcost[maxSize], vset[maxSize];
    int i, j, minj, min;
    for (i = 0; i < g.n; ++i)
    {
        lowcost[i] = g.edgeW[v][i];
        vset[i]    = 0;
    }
    for (i = 0; i < g.n; ++i)
    {
        std::cout << lowcost[i] << " ";
    }
    std::cout << "$$" << std::endl;
    vset[v] = 1;
    std::cout << v << "**" << std::endl;
    sum = 0;
    for (i = 0; i < g.n - 1; ++i)
    {
        min = 7000;
        for (j = 0; j < g.n; ++j)
        {
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min  = lowcost[j];
                minj = j;
            }
        }
        vset[min] = 1;
        std::cout << minj << "**" << std::endl;
        sum += min;
        for (j = 0; j < g.n; ++j)
        {
            if (vset[j] == 0 && g.edgeW[min][j] < lowcost[j]) lowcost[j] = g.edgeW[minj][j];
        }
        for (int p = 0; p < g.n; ++p)
        {
            std::cout << lowcost[p] << " ";
        }
        std::cout << "$$" << std::endl;
    }
}
int main(int argc, char** argv)
{
    MGraph g;
    int    sum;
    createGraph(g);
    prim(g, 2, sum);
    return 0;
}