#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 10

int op(int a, char op, int b)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/')
    {
        if (b == 0)
        {
            std::cout << "被除数不能为0" << std::endl;
            return 0;
        }
        return a / b;
    }
    std::cout << "could not op: " << op << std::endl;
    return 0;
}

int com(char exp[])
{
    int  stack[maxSize], top = -1, a, b, c;
    char opa;
    for (int i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            stack[++top] = exp[i] - '0';
        else
        {
            opa          = exp[i];
            b            = stack[top--];
            a            = stack[top--];
            c            = op(a, opa, b);
            stack[++top] = c;
        }
    }
    return stack[0];
}

int main(int argc, char** argv)
{
    char exp[10] = {'1', '2', '3', '4', '*', '+', '+', '2', '/', '\0'};
    int  i       = 0;
    std::cout << "输入为 ";
    while (i < 10) std::cout << exp[i++] << " ";
    std::cout << std::endl;
    std::cout << "计算结果为 " << com(exp) << std::endl;
    return 0;
}