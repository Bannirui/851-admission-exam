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

/**
 * 背包问题
 * sum[i][j]的语义是
 * @param n
 * @param c
 * @param v
 * @param w
 * @param sum
 */
int pack(int n, int c, int v[], int w[], int sum[][maxSize])
{
    // base case
    for (int i = 1; i <= n; ++i)
    {
        sum[i][0] = 0;
    }
    for (int i = 0; i <= c; ++i)
    {
        sum[0][i] = 0;
    }
    // 常规
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (w[i - 1] > j)
            {
                sum[i][j] = sum[i - 1][j];
            }
            else
            {
                sum[i][j] = std::max(sum[i - 1][j], sum[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= c; ++j)
        {
            std::cout << sum[i][j] << "\t";
            if (j == c)
            {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}

void traceBack(int n, int c, int w[], int sum[][maxSize], int x[])
{
    for (int i = n; i >= 1; --i)
    {
        if (sum[i][c] == sum[i - 1][c])
        {
            x[i] = 0;
        }
        else
        {
            x[i] = 1;
            c -= w[i];
        }
    }
}

int main(int argc, char** argv)
{
    int w[5] = {2, 2, 6, 5, 4};
    int v[5] = {6, 3, 5, 4, 6};
    int sum[maxSize][maxSize], x[11];
    pack(5, 10, v, w, sum);
    traceBack(5, 10, w, sum, x);
    for (int i = 1; i < 6; ++i)
    {
        std::cout << x[i] << " ";
    }
    return 0;
}