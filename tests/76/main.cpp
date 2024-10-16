#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20

int n, x[maxSize], count = 0;

bool restrict(int t) {
  for (int j = 0; j < t; ++j) {
    if ((std::abs(t - j) == std::abs(x[t] - x[j])) || (x[j] == x[t])) {
      return false;
    }
  }
  return true;
}

void backtrace(int t) {
  if (t == n) {
    ++count;
  } else {
    for (int i = 0; i < n; ++i) {
      x[t] = i;
      if (restrict(t)) {
        backtrace(t + 1);
      }
    }
  }
}

int main(int argc, char **argv) {
  for (int i = 1; i <= 10; ++i) {
    n = i;
    backtrace(0);
    std::cout << "i=" << i << ", count=" << count << std::endl;
    count = 0;
  }
  return 0;
}