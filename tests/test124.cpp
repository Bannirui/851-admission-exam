#include <cstring>
#include <iostream>
//
// Created by rui ding on 2025/7/29.
//
// 不开辟用于交换数据的临时空间 怎么完成字符串的逆序
void change(char* s)
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        // i         j
        // i^j       j
        // i^j       i^j^j=i
        // i^j^i=j   i
        s[i] ^= s[j] ^= s[i] ^= s[j];
    }
}
int main(int argc, const char** argv)
{
    char str[] = "abcdefg";
    std::cout << "逆序前 " << str << std::endl;
    change(str);
    std::cout << "逆序后 " << str << std::endl;
    return 0;
}