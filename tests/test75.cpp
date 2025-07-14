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

int M[3][2] = {{2, 1}, {3, 1}, {2, 3}};
int x[3]    = {0, 1, 2};
int bestx[3], f2[3] = {0, 0, 0}, f1 = 0, f = 0, bestf = INF, n = 3;

void backtrace(int i)
{
    if (i == n)
    {
        for (int k = 0; k < n; ++k)
        {
            std::cout << x[k] << " ";
        }
        std::cout << f << std::endl;
    }
    for (int k = i; k < n; ++k)
    {
        f1 += M[x[k]][0];
        f2[i] = ((f2[i - 1] > f1) ? f2[i - 1] : f1) + M[x[k]][1];
        f += f2[i];
        std::swap(x[k], x[i]);
        backtrace(i + 1);
        std::swap(x[i], x[k]);
        f1 -= M[x[k]][0];
        f -= f2[i];
    }
}

int main(int argc, char** argv)
{
    backtrace(0);
    return 0;
}