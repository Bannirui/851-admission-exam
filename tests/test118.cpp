#include <iostream>

#include <ostream>
//
// Created by rui ding on 2025/7/28.
//
/**
 * 字符串转数字
 * @return 字符串转成的数字
 */
int str2int(const char* str)
{
    int i = 0, sign = 1, value = 0;
    if (str == nullptr) std::cerr << "str is null" << std::endl;
    // 符号位
    if (str[0] == '-' || str[0] == '+')
    {
        i    = 1;
        sign = (str[0] == '-' ? -1 : 1);
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++)
    {
        value = value * 10 + (str[i] - '0');
    }
    return sign * value;
}
int main(int argc, char** argv)
{
    const char* str = "-123.45Cs67";
    int         val = str2int(str);
    std::cout << "str=" << str << ", val=" << val << std::endl;
    return 0;
}