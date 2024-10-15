#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

/**
 * 对数组arr[lo...hi]快排
 */
void QuickSort(int arr[], int lo, int hi) {
  if (lo >= hi)
    return;
  int tmp, i = lo, j = hi;
  // 基准
  tmp = arr[lo];
  while (i < j) {
    // 先看右边 保证右边都是比基准大的数字
    while (i < j && arr[j] >= tmp)
      --j;
    // 右边的这个数字要挪到左边去
    if (i < j) {
      arr[i] = arr[j];
      ++i;
    }
    // 再看左边 保证左边都是比基准小的数字
    while (i < j && arr[i] < tmp)
      ++i;
    // 左边的这个数字要挪到右边去
    if (i < j) {
      arr[j] = arr[i];
      --j;
    }
  }
  // 左右相对基准已经相对有序 把基准的值放到当前悬停的脚标i
  arr[i] = tmp;
  QuickSort(arr, lo, i - 1);
  QuickSort(arr, i + 1, hi);
}

int main(int argc, char **argv) {
  int arr[8] = {1, 4, 3, 2, -4, 99, 5, 7};
  std::cout << "数组排序前 ";
  for (int i = 0; i < 8; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  QuickSort(arr, 0, 7);

  std::cout << "数组排序后 ";
  for (int i = 0; i < 8; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  return 0;
}