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

void swap(char &a, char &b) {
  char tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void print_arr(char arr[], int sz) {
  for (int i = 0; i < sz; ++i)
    std::cout << arr[i];
  std::cout << std::endl;
}

/**
 * 对数组x[k...m]进行全排列
 * @param sz 数组长度
 */
void perm(char x[], int sz, int s, int e) {
  if (s == e) {
    // 处理到数组中只有一个元素 收集结果的信号
    print_arr(x, sz);
  } else {
    for (int i = s; i <= e; ++i) {
      swap(x[i], x[s]);
      perm(x, sz, s + 1, e);
      // 恢复现场
      swap(x[i], x[s]);
    }
  }
}

int main(int argc, char **argv) {
  char x[4] = {'1', '2', '3', '4'};
  perm(x, 4, 0, 3);
  return 0;
}