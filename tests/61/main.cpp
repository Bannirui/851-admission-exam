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

int main(int argc, char **argv) {

  int n = 4;
  std::cout << "递归计算 输入=" << n << ", 输出=" << cal(4) << std::endl;
  return 0;
}