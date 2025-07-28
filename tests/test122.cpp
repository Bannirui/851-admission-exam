//
// Created by rui ding on 2025/7/28.
//

#include <iostream>

#include <ostream>
// 删除字符串中的数字并压缩字符串
// abc123de4fgg->abcdefg
void delNum(char* str)
{
    int i, j = 0;
    // 找到字符串中第1个数字位置
    for (i = j = 0; str[i] && (str[i] < '0' || str[i] > '9'); j = ++i);
    for (; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            str[j++] = str[i];
        }
    }
    // [0...j)全是非数字了 在j的位置插上字符串结束符
    str[j] = '\0';
}

int main(int argc, const char** argv)
{
    char str[] = "abc123de4fg5";
    std::cout << str << std::endl;
    delNum(str);
    std::cout << str << std::endl;
    return 0;
}