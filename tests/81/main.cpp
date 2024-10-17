#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

void greedyManagement(int n, int s[], int f[], bool A[]) {
  A[0] = true;
  int j = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] >= f[j]) {
      A[i] = true;
      j = i;
    } else {
      A[i] = false;
    }
  }
}

int main(int argc, char **argv) {
  int s[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12},
      f[11] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  bool A[11];
  greedyManagement(11, s, f, A);
  for (int i = 0; i < 11; ++i) {
    if (A[i] == true) {
      std::cout << "i=" << i << std::endl;
    }
  }
  return 0;
}