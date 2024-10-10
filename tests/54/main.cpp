#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 10

/**
 * 校验输入字符串中括号对是否闭合匹配
 * @param A 字符串
 * @return 1标识匹配 0标识不匹配
 */
int match(char A[], int n) {
  char stack[maxSize];
  int top = -1;

  for (int i = 0; i < n; ++i) {
    if (A[i] == '(') {
      ++top;
      stack[top] = '(';
    } else if (A[i] == ')') {
      if (top == -1)
        return 0;
      else
        --top;
    }
  }
  if (top == -1)
    return 1;
  return 0;
}

int main(int argc, char **argv) {
  char exp[8] = {'(', '-', '(', '+', '3', ')', ')', '\0'};
  int i = 0;
  std::cout << "输入为 ";
  while (i < 8)
    std::cout << exp[i++] << " ";
  std::cout << std::endl;
  std::cout << "该字符串中括号匹配闭合 " << match(exp, 8) << std::endl;
  return 0;
}