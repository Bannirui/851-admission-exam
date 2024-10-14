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

/**
 * 二分查找 折半查找
 * @param sz 数组长度
 * @param target 要查找的数字
 * @return 查找到的元素脚标 -1标识没找到
 */
int bs(int arr[], int sz, int target) {
  int l = 0, r = sz - 1;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      l = mid + 1;
    else if (arr[mid] > target)
      r = mid - 1;
  }
  return -1;
}

int main(int argc, char **argv) {
  int arr[8] = {1, 5, 9, 11, 23, 31, 57, 89};
  int target = 110;
  std::cout << "从数组" << arr << "中找数字" << target << " 结果是"
            << bs(arr, 8, target) << std::endl;
  return 0;
}