//
// Created by rui ding on 2025/7/15.
//

// 将一整数逆序后放入一数组中

#include <cstdio>
void convert(int* ret, int n)
{
    if (n >= 10) convert(ret + 1, n / 10);
    *ret = n % 10;
}

int main(int argc, char** argv)
{
    int n       = 13579;
    int ret[20] = {};
    convert(ret, n);
    for (int i = 0; i < 20; i++)
    {
        printf("%d is %d\n", i, ret[i]);
    }
    return 0;
}