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

int edgesW[5][5] = {
    {INF, 1, INF, 1, 1}, {1, INF, 1, INF, 1}, {INF, 1, INF, INF, 1}, {1, INF, INF, INF, 1}, {1, 1, 1, 1, INF}};
int x[maxSize], bestx[maxSize], sum = 0, n = 5, m = 3;

bool ok(int i)
{
    for (int j = 0; j < n; ++j)
    {
        if ((edgesW[j][i] == 1) && (x[i] == x[j]))
        {
            return false;
        }
    }
    return true;
}

void backtrace(int i)
{
    if (i == n)
    {
        ++sum;
        for (int j = 0; j < n; ++j)
        {
            std::cout << x[j] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int j = 0; j < n; ++j)
    {
        x[i] = j;
        if (ok(i))
        {
            backtrace(i + 1);
        }
        x[i] = -1;
    }
}

int main(int argc, char** argv)
{
    for (int i = 0; i < n; ++i)
    {
        x[i] = -1;
    }
    backtrace(0);
    std::cout << "sum=" << sum << std::endl;
    return 0;
}