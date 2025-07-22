#include <iostream>
//
// Created by rui ding on 2025/7/22.
//
/**
 * 乘法
 * @param n1 乘数 字符串形式
 * @param n2 被乘数 字符串形式
 * @param ret 乘法结果
 */
void multiple(char n1[], char n2[], char ret[])
{
    int tmp, carry = 0;
    // 初始化为-1的原因是统计完字符串长度后让len等于有效长度 不包含\0结束符的长度
    int lenA = -1, lenB = -1;
    // 计算n1字符串长度
    while (n1[++lenA] != '\0');
    // 计算n2字符串长度
    while (n2[++lenB] != '\0');
    int index, start = lenA + lenB - 1;
    for (int i = lenB - 1; i >= 0; i--)
    {
        index = start--;
        if (n2[i] != '\0')
        {
            for (int ln = 0, j = lenA - 1; j >= 0; j--)
            {
                tmp          = (ret[index] - '0') + (n1[j] - '0') * (n2[i] - '0') + ln;
                ret[index--] = tmp % 10 + '0';
                // 进位
                carry = tmp / 10;
            }
            ret[index] = carry + '0';
        }
    }
}

int main(int argc, char** argv)
{
    // 字符串
    char n1[] = "11";
    char n2[] = "11";
    char ret[sizeof(n1) + sizeof(n2) - 1];
    // 初始化ret
    for (int i = 0; i < sizeof(ret); i++) ret[i] = '0';
    ret[sizeof(ret) - 1] = '\0';

    multiple(n1, n2, ret);
    for (int i = 0; ret[i] != '\0'; i++)
    {
        if (ret[i] == '0') continue;
        std::cout << ret[i];
    }
    std::cout << std::endl;
}