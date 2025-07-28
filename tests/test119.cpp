#include <cmath>
#include <iostream>
#include <ostream>
//
// Created by rui ding on 2025/7/28.
//
// 任何一个偶数都可以分解成两个素数之和
int main(int argc, const char** argv)
{
    int even = 78, prim1, prim2, tmp1, tmp2;
    for (prim1 = 3; prim1 <= even / 2; prim1 += 2)
    {
        for (tmp1 = 2, tmp2 = sqrt(float(prim1)); tmp1 <= tmp2 && prim1 % tmp1 != 0; tmp1++);
        if (tmp1 <= tmp2) continue;
        prim2 = even - prim1;
        for (tmp1 = 2, tmp2 = sqrt(float(prim2)); tmp1 <= tmp2 && prim2 % tmp1 != 0; tmp1++);
        if (tmp1 <= tmp2) continue;
        std::cout << even << "=" << prim1 << "+" << prim2 << std::endl;
    }
    return 0;
}