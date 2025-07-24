//
// Created by rui ding on 2025/7/23.
//
#include <iostream>
/**
 * 在父串中找子串首次出现的位置
 * @param p 父串
 * @param s 子串
 * @return 子串出现在父串中的位置 从那个位置到父串最后
 */
char* strstr(char* p, char* s)
{
    char *pp, *sp;
    for (char* pTmp = p; *pTmp; pTmp++)
    {
        sp = s;
        pp = pTmp;
        // 父串[pTmp...] 子串[sp...]逐个比较字符
        while (*sp == *pp && *sp != '\0')
        {
            sp++;
            pp++;
        }
        // 到了子串结束符 说明整个子串都能在父串中找到 在父串的pTmp位置
        if (*sp == '\0') return pTmp;
    }
    return nullptr;
}
int main(int argc, const char** argv)
{
    const char* p = "happy birthday to you";
    const char* s = "birthday";
    std::cout << strstr(p, s) << std::endl;
    return 0;
}
