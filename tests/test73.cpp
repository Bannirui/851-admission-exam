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

int p[6][6] = {{0, 2, 2, 3, 1, 4}, {2, 0, 1, 5, 2, 3}, {2, 1, 0, 2, 1, 4},
               {3, 5, 2, 0, 6, 2}, {1, 2, 1, 6, 0, 1}, {4, 3, 4, 2, 1, 0}};

int w(int i, int j, int k)
{
    return p[i][j] + p[k][j] + p[i][k];
}

void triangleDivide(int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            m[i][j] = -1;
            s[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        m[i][i] = 0;
    }
    for (int r = 2; r <= n; ++r)
    {
        for (int i = 1; i <= n - r + 1; ++i)
        {
            int j   = i + r - 1;
            m[i][j] = m[i + 1][j] + w(i - 1, i, j);
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k)
            {
                int t = m[i][k] + m[k + 1][j] + w(i - 1, k, j);
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cout << m[i][j] << "\t";
            if (j == n) std::cout << std::endl;
        }
    }
}

void Traceback(int i, int j, int s[][maxSize])
{
    if (i == j)
    {
        return;
    }
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);
    std::cout << "V" << i - 1 << ", V" << j << ", V" << s[i][j] << std::endl;
}

int main(int argc, char** argv)
{
    int m[maxSize][maxSize], s[maxSize][maxSize];
    triangleDivide(6, m, s);
    Traceback(1, 5, s);
    return 0;
}