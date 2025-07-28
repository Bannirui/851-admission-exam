#include <cstdlib>
#include <iostream>
//
// Created by rui ding on 2025/7/28.
//
// 求两个串中第一个最长子串
// abractyeyt和dgdsaeactyey的最长子中是actyey
char* maxSubString(const char* s, const char* t)
{
    int i, j, k, index, max = 0;
    // 从s出发每个字符为开始找一下在t中最长的相同串
    for (i = 0; s[i]; i++)
    {
        for (j = 0; t[j]; j++)
        {
            for (k = 0; s[i + k] == t[j + k] && (s[i + k] || t[j + k]); k++);
            if (k > max)
            {
                index = j;
                max   = k;
            }
        }
    }
    char* ret = (char*)calloc(sizeof(char), max + 1);
    for (i = 0; i < max; i++)
    {
        ret[i] = t[index++];
    }
    return ret;
}
int main(int argc, const char** argv)
{
    const char* s = "abractyeyt";
    const char* t = "dgdsaeactyey";
    std::cout << "s=" << s << ", t=" << t << ", max sub=" << maxSubString(s, t) << std::endl;
    return 0;
}