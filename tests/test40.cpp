#include <iostream>
#ifdef __linux__
#include <malloc.h>
#endif

#define maxSize 20

char VName[5]     = {'A', 'B', 'C', 'D', 'E'};
int  weight[5][5] = {{0, 3, 2, 4, 1}, {3, 0, 5, 0, 6}, {2, 5, 0, 2, 0}, {4, 0, 2, 0, 0}, {1, 6, 0, 0, 0}};

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
void createGraph(MGraph g)
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
int main(int argc, char** argv)
{
    MGraph g;
    createGraph(g);
    return 0;
}