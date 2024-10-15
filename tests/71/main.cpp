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

void LCSLength(int m, int n, char x[], char y[], int c[][maxSize],
               int b[][maxSize]) {
  for (int i = 1; i <= m; ++i) {
    c[i][0] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    c[0][i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i] == y[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 1;
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
        b[i][j] = 2;
      } else {
        c[i][j] = c[i][j - 1];
        b[i][j] = 3;
      }
    }
  }
}

void traceBack(int i, int j, char x[], int b[][maxSize]) {
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == 1) {
    traceBack(i - 1, j - 1, x, b);
    std::cout << x[i];
  } else if (b[i][j] == 2) {
    traceBack(i - 1, j, x, b);
  } else {
    traceBack(i, j - 1, x, b);
  }
}

int main(int argc, char **argv) {
  char x[8] = {' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
  char y[7] = {' ', 'B', 'D', 'C', 'A', 'B', 'A'};
  int c[maxSize][maxSize], b[maxSize][maxSize];
  LCSLength(7, 6, x, y, c, b);

  for (int i = 0; i <= 7; ++i) {
    for (int j = 0; j <= 6; ++j) {
      std::cout << c[i][j] << "\t";
      if (j == 6) {
        std::cout << std::endl;
      }
    }
  }
  traceBack(6, 7, x, b);
  return 0;
}