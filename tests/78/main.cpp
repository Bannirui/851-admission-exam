#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

typedef struct VexNode
{
    int no;
} VexNode;

typedef struct MGraph
{
    int edges[maxSize][maxSize];
    int v, e;
    VexNode vex[maxSize];
} MGraph;

int edgesW[5][5] = {INF, 1, INF, 1,   1,   1,   INF, 1, INF, 1, INF, 1,  INF,
                    INF, 1, 1,   INF, INF, INF, 1,   1, 1,   1, 1,   INF};

int x[maxSize], bestx[maxSize], cn = 0, bestn = 0, n = 5;

void backtrace(int i)
{
    if (i == n)
    {
        for (int j = 0; j < n; ++j)
        {
            bestx[j] = x[j];
        }
        bestn = cn;
        return;
    }
    int flag = 1;
    for (int j = 0; j < i; ++j)
    {
        if (x[j] && edgesW[i][j] == INF)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        x[i] = 1;
        cn++;
        backtrace(i + 1);
        x[i] = 0;
        cn--;
    }
    if (cn + n - i - 1 > bestn)
    {
        x[i] = 0;
        backtrace(i + 1);
    }
}

int main(int argc, char **argv)
{
    MGraph g;
    g.e = 7;
    g.v = n;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            g.edges[i][j] = edgesW[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) x[i] = 0;
    backtrace(0);
    std::cout << "结果为" << std::endl;
    for (int i = 0; i < 5; ++i) std::cout << bestx[i] << " ";
    return 0;
}