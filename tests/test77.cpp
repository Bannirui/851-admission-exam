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

int n, w[4] = {1, 2, 3, 5}, v[4] = {4, 7, 9, 10}, cw, cv, c, bestv;

int bound(int i)
{
    int   cleft = c - cw;
    float b     = cv * 1.0;
    while (i < n && w[i] <= cleft)
    {
        b += v[i];
        cleft -= w[i];
        i++;
    }
    if (i < n)
    {
        b += v[i] * 1.0 * cleft / w[i];
    }
    return b;
}

void backtrace(int i)
{
    if (i == n)
    {
        if (cv > bestv)
        {
            bestv = cv;
            std::cout << i << std::endl;
            return;
        }
    }
    if (cw + w[i] <= c)
    {
        cw += w[i];
        cv += v[i];
        backtrace(i + 1);
        cw -= w[i];
        cv -= v[i];
    }
    if (bound(i + 1) > bestv)
    {
        backtrace(i + 1);
    }
}

int main(int argc, char** argv)
{
    n = 4, c = 7, cw = 0, cv = 0, bestv = 0;
    backtrace(0);
    std::cout << "bestv=" << bestv << std::endl;
    return 0;
}