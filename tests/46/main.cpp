#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 100

typedef struct Sqlist {
  int data[maxSize];
  int length;
} Sqlist;

void initList(Sqlist &L) {
  L.length = 9;
  L.data[0] = 4;
  L.data[1] = 5;
  L.data[2] = 7;
  L.data[3] = 9;
  L.data[4] = 10;
  L.data[5] = 13;
  L.data[6] = 17;
  L.data[7] = 21;
}

int getElem(Sqlist &L, int p, int &e) {
  if (p < 0 || p > L.length - 1)
    return 0;
  e = L.data[p];
  return 1;
}

/**
 * @return 元素在数组中的脚标位置 -1标识没有找到
 */
int findElem(Sqlist L, int x) {
  int i;
  for (i = 0; i < L.length; ++i) {
    if (x == L.data[i])
      return i;
  }
  return -1;
}

/**
 * @return 0标识失败 1标识成功
 */
int insertElem(Sqlist &L, int p, int e) {
  int i;
  if (p < 0 || p > L.length || L.length == maxSize)
    return 0;
  for (i = L.length - 1; i >= p; --i)
    L.data[i + 1] = L.data[i];
  L.data[p] = e;
  ++L.length;
  return 1;
}

/**
 * @return 0标识失败 1标识成功
 */
int deleteElem(Sqlist &L, int p, int &e) {
  int i;
  if (p < 0 || p > L.length - 1)
    return 0;
  e = L.data[p];
  for (i = p; i < L.length; ++i) {
    L.data[i] = L.data[i + 1];
  }
  --(L.length);
  return 1;
}

int main(int argc, char **argv) {
  Sqlist list;
  int e;

  initList(list);
  int target = 17;
  std::cout << "查找元素" << target << "在数组中脚标位置为"
            << findElem(list, target) << std::endl;
  std::cout << "获取元素结果 " << getElem(list, 5, e) << std::endl;
  std::cout << "获取到的元素为 " << e << std::endl;
  return 0;
}