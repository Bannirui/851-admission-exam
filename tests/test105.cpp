#include <iostream>
//
// Created by rui ding on 2025/7/15.
//
// 组合问题
// 从M个不同的字符中任取N个字符的所有组合
/**
 * 从字符串src中任取n个字符拼接到ret后面组成新的字符串
 * @param src 字符串\0结束符
 * @param ret 已经找到字符拼成的字符串 \0结束符
 * @param n 还要从src中找几个字符
 */
void find(char* src, char* ret, int n)
{
    // 只要再从src中找1个字符 整个src中能用的有1个算1个拼到ret后面就形成了完整的字符串
    if (n == 1)
    {
        while (*src)
        {
            printf("%s%c\n", ret, *src++);
        }
    }
    else
    {
        int i, j;
        // i是src的长度 n是要找的字符串长度 从src中挑出来的字符缓存在ret中 然后递归
        for (i = 0; src[i] != '\0'; i++);
        // j指向ret的最后 \0结束符位置 准备添加新挑选的字符
        for (j = 0; ret[j] != '\0'; j++);
        for (; i >= n; i--)
        {
            ret[j]     = *src++;
            ret[j + 1] = '\0';
            find(src, ret, n - 1);
        }
    }
}

int main()
{
    int const n     = 3;
    char      src[] = "ABCDE\0";
    // 预留占位\0
    char ret[n + 1] = {0};
    if (n > 0 && strlen(src) > 0 && n <= strlen(src))
    {
        find(src, ret, n);
    }
    return 0;
}