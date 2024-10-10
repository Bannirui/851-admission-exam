#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

void reverse(int arr[], int m, int n) {
  int tmp, i, j;
  for (i = m; i < m + n; ++i) {
    tmp=arr[i];
    for (j = i - 1; j >= 0 && arr[j] < arr[i]; --j) {
      arr[j + 1] = arr[j];
    }
    arr[j] = tmp;
  }
}

int main(int argc, char **argv) {
  int arr[9] = {1, 3, 5, 1, 2, 3, 4, 6, 7};
  std::cout << "翻转前数组为 ";
  for (int i = 0; i < 9; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  reverse(arr, 3, 6);
  std::cout << "翻转后数组为 ";
  for (int i = 0; i < 9; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  return 0;
}