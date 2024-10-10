#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode;

/**
 * 根据数组中值创建节点形成链表
 * @param L 单链表哨兵节点
 */
int createLNodeR(LNode *&L, int arr[], int n) {
  int i;
  LNode *r, *s;
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  r = L;
  for (i = 0; i < n; ++i) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = arr[i];
    r->next = s;
    r = r->next;
  }
  r->next = NULL;
  return 1;
}

int findAndDelete(LNode *A, LNode *B) {
  LNode *a, *b, *c;
  b = B;
  while (b->next != NULL) {
    a = A;
    while (a->next != NULL) {
      if (a->next->data == b->next->data) {
        c = a->next;
        a->next = a->next->next;
        free(c);
      }
      a = a->next;
    }
    b = b->next;
  }
  return 1;
}

int difference(LNode *A, LNode *B) {
  LNode *a, *b, *c;
  a = A;
  b = B;
  while (a->next != NULL && b->next != NULL) {
    if (a->next->data < b->next->data)
      a = a->next;
    else if (a->next->data > b->next->data)
      b = b->next;
    else {
      // 缓存待删除
      c = a->next;
      a->next = a->next->next;
      a = a->next;
      free(c);
    }
  }
  return 1;
}

int main(int argc, char **argv) {
  LNode *A, *B, *a, *b;
  int arr_a[5] = {1, 3, 5, 7, 9};
  int arr_b[4] = {1, 2, 3, 7};
  createLNodeR(A, arr_a, 5);
  createLNodeR(B, arr_b, 4);
  a = A;
  b = B;

  std::cout << "链表A的节点为 ";
  for (int i = 0; i < 6; ++i) {
    std::cout << a->data << "--";
    a = a->next;
  }
  std::cout << std::endl;

  std::cout << "链表B的节点为 ";
  for (int i = 0; i < 5; ++i) {
    std::cout << b->data << "--";
    b = b->next;
  }
  std::cout << std::endl;

  difference(A, B);

  a = A;
  b = B;
  std::cout << "链表A的节点为 ";
  while (a != NULL) {
    std::cout << a->data << "--";
    a = a->next;
  }
  std::cout << std::endl;

  std::cout << "链表B的节点为 ";
  while (b != NULL) {
    std::cout << b->data << "--";
    b = b->next;
  }
  std::cout << std::endl;
  return 0;
}