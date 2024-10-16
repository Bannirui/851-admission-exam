#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

int cw = 0, bestw = 0;
int x[3], bestx[3];

void backtrace(int i, int w[], int c, int n) {
  if (i >= n) {
    if (cw > bestw) {
      for (int j = 0; j < n; ++j) {
        bestx[j] = x[j];
        bestw = cw;
      }
    }
    return;
  }
  if (cw + w[i] <= c) {
    cw += w[i];
    x[i] = 1;
    backtrace(i + 1, w, c, n);
    cw -= w[i];
  }
  x[i] = 0;
  backtrace(i + 1, w, c, n);
}

int main(int argc, char **argv) {
  int w[3] = {10, 40, 40};
  int c1 = 50, c2 = 50, n = 3;
  for (int j = 0; j < n; ++j) {
    x[j] = -1;
  }
  backtrace(0, w, c1, n);
  std::cout << "bestw=" << bestw << std::endl;
  for (int j = 0; j < n; ++j) {
    std::cout << bestx[j] << std::endl;
  }
  return 0;
}