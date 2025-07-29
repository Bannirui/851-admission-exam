#include <iostream>
//
// Created by rui ding on 2025/7/29.
//
/**
 * 删除串中指定的字符 不要开辟新的内存空间
 * 从字符串str中删除ch
 */
void delChar(char* str, char ch)
{
    // 双指针 i负责考察字符串 [0...j)是已经确认删除过字符的结果
    int i, j = 0;
    for (i = 0; str[i]; i++)
    {
        if (str[i] != ch)
        {
            // 不需要删除的字符 挪到结果区
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
int main(int argc, char** argv)
{
    char str[] = "abcdefgh";
    std::cout << str << std::endl;
    delChar(str, 'z');
    std::cout << str << std::endl;
    return 0;
}