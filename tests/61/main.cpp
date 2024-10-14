#include <algorithm>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

int cal(int n) {
  if (n == 0)
    return 1;
  return n * cal(n - 1);
}

int fab(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fab(n - 1) + fab(n - 2);
}

int main(int argc, char **argv) {

  int n = 4;
  std::cout << "递归 阶乘 输入=" << n << ", 输出=" << cal(4) << std::endl;
  std::cout << "递归 斐波那契数列 输入=" << n << ", 输出=" << fab(n)
            << std::endl;
  return 0;
}