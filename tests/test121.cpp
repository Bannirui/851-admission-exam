//
// Created by rui ding on 2025/7/28.
//

#include <iostream>

#include <ostream>
// 判断数字是不是回文数
int isEchoNum(int num)
{
    int tmp = 0;
    for (int n = num; n; n /= 10)
    {
        tmp = tmp * 10 + n % 10;
    }
    return tmp == num;
}

int main(int argc, const char** argv)
{
    int num = 12321;
    std::cout << num << ": " << isEchoNum(num) << std::endl;
    return 0;
}