//
// Created by rui ding on 2025/7/15.
//
// 递归实现回文判断
// abcdedcba就是回文
#include <iostream>
/**
 *
 * @param str 字符串
 * @param len 长度
 * @return 1是回文 0不是
 */
int find(char* str, int len)
{
    if (len <= 1) return 1;
    if (str[0] == str[len - 1]) return find(str + 1, len - 2);
    return 0;
}

int main()
{
    char str[] = "abcedcba";
    std::cout << str << ": " << (find(str, strlen(str)) ? "Yes" : "No") << std::endl;
}