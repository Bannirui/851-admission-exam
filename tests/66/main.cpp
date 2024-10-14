#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

void merge_arr(int arr[], int first, int mid, int last, int ret[]) {
  int i = first, j = mid + 1;
  int m = mid, n = last;
  int k = 0;
  // 数组arr的两个部分合并到一个数组ret中 arr[first...mid)和arr(mid...last]
  while (i <= m && j <= n) {
    if (arr[i] <= arr[j])
      ret[k++] = arr[i++];
    else
      ret[k++] = arr[j++];
  }
  // arr数组两个部分长度不一的时候剩下另一个部分直接追加到ret中
  while (i <= m)
    ret[k++] = arr[i++];
  while (j <= n)
    ret[k++] = arr[j++];
  // ret中已经存好了有序结果 将arr的元素顺序同步给源数组
  for (int i = 0; i < k; ++i)
    arr[first + i] = ret[i];
}

/**
 * @param arr 源数组 arr[fisrt...last]进行归并排序
 * @param ret 排序好的结果存放
 */
void merge_sort(int arr[], int first, int last, int ret[]) {
  // base
  if (first >= last)
    return;
  int mid = first + ((last - first) >> 1);
  // [first...mid)
  merge_sort(arr, first, mid, ret);
  // (mid...last)
  merge_sort(arr, mid + 1, last, ret);
  // 合并两个数组
  merge_arr(arr, first, mid, last, ret);
}

int main(int argc, char **argv) {
  int arr[8] = {1, 4, 2, -4, 3, 99, 5, 7};
  // 排序结果数组
  int ret[8];
  merge_sort(arr, 0, 7, ret);
  std::cout << "数组排序结果";
  for (int i = 0; i < 8; ++i) {
    std::cout << ret[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}