#include <iostream>
//
// Created by rui ding on 2025/7/28.
//
// 将字符串中的*移到前部分 前面非*字符后移 但不能改变先后顺序
// 函数返回字符串中*的数量
// ab**cd**e*12->*****abcde12
int change(char* s)
{
    // 双指针
    int i, j = strlen(s);
    for (i = j; j >= 0; j--)
    {
        // 从后往前找 一直找到*
        if (s[i] != '*')
        {
            i--;
        }
        else if (s[j] != '*')
        {
            s[i] = s[j];
            s[j] = '*';
            i--;
        }
    }
    return i + 1;
}
int main(int argc, char** argv)
{
    char s[] = "ab**cd**e*12";
    std::cout << "str1=" << s << std::endl;
    std::cout << "count=" << change(s) << ", str2=" << s << std::endl;
    return 0;
}