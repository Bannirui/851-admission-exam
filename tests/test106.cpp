//
// Created by rui ding on 2025/7/17.
//
#include <stdio.h>

// 分解成质因数
// 435234=251*17*17*3*2
void prim(int m, int n)
{
    if (m > n)
    {
        while (m % n != 0) n++;
        m /= n;
        prim(m, n);
        printf("%d*", n);
    }
}
int main(int argc, char** argv)
{
    int n = 435234;
    printf("%d=", n);
    prim(n, 2);
    return 0;
}