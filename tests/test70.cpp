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
 * @param n 矩阵大小
 */
void matrixChain(int p[], int n, int m[][maxSize], int s[][maxSize])
{
    // 数组值初始化为-1 矩阵对角线值0
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            m[i][j] = -1;
            if (i == j)
            {
                m[i][j] = 0;
            }
        }
    }
    for (int r = 2; r < n; ++r)
    {
        for (int i = 1; i < n + 1 - r; ++i)
        {
            int j   = r + i - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;

            for (int k = i + 1; k < j; ++k)
            {
                int t = m[i][k] + p[i - 1] * p[k] * p[j] + m[k + 1][j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void traceBack(int i, int j, int s[][maxSize])
{
    if (i == j)
    {
        return;
    }
    traceBack(i, s[i][j], s);
    traceBack(s[i][j] + 1, j, s);
    std::cout << "A" << i << ", " << s[i][j] << " and A" << (s[i][j] + 1) << ", " << j << std::endl;
}

int main(int argc, char** argv)
{
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int m[maxSize][maxSize], s[maxSize][maxSize];
    matrixChain(p, 7, m, s);
    traceBack(1, 6, s);
    return 0;
}