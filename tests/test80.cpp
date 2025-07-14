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

#define maxSize 20
#define INF 1000

int edgesW[4][4] = {{INF, 30, 6, 4}, {30, INF, 5, 10}, {6, 5, INF, 20}, {4, 10, 20, INF}};

int x[maxSize], bestx[maxSize], cv = 0, n = 4, bestv = INF;

void backtrace(int i)
{
    if (i == n - 1)
    {
        if (edgesW[x[n - 2]][x[i]] != INF && edgesW[x[i]][0] != INF &&
            (cv + edgesW[x[n - 2]][x[i]] + edgesW[x[i]][0] < bestv || bestv == INF))
        {
            for (int j = 0; j < n; ++j)
            {
                bestx[j] = x[j];
            }
            bestv = cv + edgesW[x[n - 2]][x[i]] + edgesW[x[i]][0];
            return;
        }
    }
    for (int j = i; j < n; ++j)
    {
        if (edgesW[x[i - 1]][x[j]] != INF && (cv + edgesW[x[i - 1]][x[j]] < bestv || bestv == INF))
        {
            std::swap(x[i], x[j]);
            cv += edgesW[x[i - 1]][x[i]];
            backtrace(i + 1);
            cv -= edgesW[x[i - 1]][x[i]];
            std::swap(x[i], x[j]);
        }
    }
}

int main(int argc, char** argv)
{
    for (int i = 0; i < n; ++i) x[i] = i;
    backtrace(1);
    std::cout << "bestv=" << bestv << std::endl;
    return 0;
}