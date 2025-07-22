#include <iostream>
//
// Created by rui ding on 2025/7/22.
//
// 求最大连续递增数字串
// ads3sl456789df3456ld345aa中的结果是456789
/**
 * @param ret 找到的结果放在ret字符串
 * @return 最大连续递增字符串长度
 */
int getSubString(char* src, char* ret)
{
    int tmp = 0;
    // 出现的连续字符串 第1个数据的脚标
    int head = 0;
    // 最长的连续数字
    int maxLen = 0;
    for (int i = 0, len = 0; src[i]; i++)
    {
        // 连续数字就一直往后找
        if (src[i] >= '0' && src[i] <= '9' && i - 1 >= 0 && src[i] == src[i - 1] + 1)
        {
            len++;
        }
        else
        {
            // 什么时候执行到这 当前在src第一个位置要特殊处理 数字不连续了
            if (src[i] >= '0' && src[i] <= '9')
            {
                tmp = i;
                len = 1;
            }
            if (len > maxLen)
            {
                maxLen = len;
                head   = tmp;
            }
        }
    }
    for (tmp = 0; tmp < maxLen; tmp++)
    {
        ret[tmp] = src[head++];
    }
    ret[tmp] = '\0';
    return maxLen;
}
int main(int argc, char** argv)
{
    char src[] = "3sl456789df3456ld345aa";
    char ret[sizeof(src)];
    std::cout << "len=" << getSubString(src, ret) << ", ret=" << ret << ", src=" << src << std::endl;
    return 0;
}