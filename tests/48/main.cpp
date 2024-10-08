#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 100

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode;

void createLNodeR(LNode *&L, int arr[], int n) {
  LNode *r, *s;
  int i;
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
}

/**
 * 单链表头插法.
 @param L 链表哨兵节点
 @param arr 候选数组
 @param sz arr数组长度
 */
void createLNodeL(LNode *&L, int arr[], int sz) {
  LNode *s;
  int i;
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  for (i = 0; i < sz; ++i) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = arr[i];
    s->next = L->next;
    L->next = s;
  }
}

int main(int argc, char **argv) {
  int arr[4] = {1, 2, 3, 4};
  LNode *L, *l;
  createLNodeL(L, arr, 4);
  l = L;
  while (l->next) {
    l = l->next;
    std::cout << l->data << "..";
  }
  std::cout << std::endl;
  return 0;
}