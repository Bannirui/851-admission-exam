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

/**
 * 源数组中元素拷贝到目标数组中 除了脚标rmIdx
 * @param n 数组长度
 * @param rmIdx 不要复制是元素是哪个
 */
void deleteElem(char src[], char dest[], int n, int rmIdx) {
  for (int i = 0; i < rmIdx; ++i)
    dest[i] = src[i];
  for (int i = rmIdx; i < n - 1; ++i)
    dest[i] = src[i + 1];
}

char stack[maxSize];
int top = -1;
/**
 * 数组x的全排列
 * @param x 数组
 * @param n 数组长度
 */
void perm(char x[], int n) {
  if (n == 0) {
    return;
  }
  char arr[maxSize];
  for (int i = 0; i < n; ++i) {
    // 元素放到栈中 数组中除了这个元素继续递归
    stack[++top] = x[i];
    // 除了i脚标位置 其他位置元素都复制到arr数组中
    deleteElem(x, arr, n, i);
    perm(arr, n - 1);
    if (n == 1) {
      for (int i = 0; i < 4; ++i) {
        std::cout << stack[i];
      }
      std::cout << std::endl;
    }
    --top;
  }
}

int main(int argc, char **argv) {
  int n = 4;
  std::cout << "递归 阶乘 输入=" << n << ", 输出=" << cal(4) << std::endl;
  std::cout << "递归 斐波那契数列 输入=" << n << ", 输出=" << fab(n)
            << std::endl;

  char x[4] = {'1', '2', '3', '4'};
  perm(x, 4);
  return 0;
}