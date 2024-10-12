#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20

typedef struct BTNode {
  int data;
  struct BTNode *lchild;
  struct BTNode *rchild;
} BTNode;

// 二叉树
typedef struct St {
  BTNode *p;
  int l;
} St;

void createTree(BTNode *&T) {
  BTNode *a, *b, *c, *d, *e, *f, *g, *h, *i;

  T = (BTNode *)malloc(sizeof(BTNode));
  T->data = 1;
  a = (BTNode *)malloc(sizeof(BTNode));
  a->data = 2;
  b = (BTNode *)malloc(sizeof(BTNode));
  b->data = 3;
  c = (BTNode *)malloc(sizeof(BTNode));
  c->data = 4;
  d = (BTNode *)malloc(sizeof(BTNode));
  d->data = 5;
  e = (BTNode *)malloc(sizeof(BTNode));
  e->data = 6;
  f = (BTNode *)malloc(sizeof(BTNode));
  f->data = 7;
  g = (BTNode *)malloc(sizeof(BTNode));
  g->data = 8;
  h = (BTNode *)malloc(sizeof(BTNode));
  h->data = 9;
  i = (BTNode *)malloc(sizeof(BTNode));
  i->data = 10;

  T->lchild = a;
  T->rchild = b;
  a->lchild = c;
  a->rchild = NULL;
  b->lchild = d;
  b->rchild = e;
  c->lchild = NULL;
  c->rchild = f;
  d->lchild = g;
  d->rchild = h;
  e->lchild = NULL;
  e->rchild = i;
  f->lchild = NULL;
  f->rchild = NULL;
  g->lchild = NULL;
  g->rchild = NULL;
  h->lchild = NULL;
  h->rchild = NULL;
  i->lchild = NULL;
  i->rchild = NULL;
}

int levelOrder(BTNode *T) {
  int rear = 0, front = 0;
  int L = 0;
  int n, max;
  St qu[maxSize];
  BTNode *r;
  if (T != NULL) {
    ++rear;
    qu[rear].p = T;
    qu[rear].l = 1;
    while (rear != front) {
      ++front;
      r = qu[front].p;
      L = qu[front].l;
      if (r->lchild != NULL) {
        ++rear;
        qu[rear].p = r->lchild;
        qu[rear].l = L + 1;
      }
      if (r->rchild != NULL) {
        ++rear;
        qu[rear].p = r->rchild;
        qu[rear].l = L + 1;
      }
    }
    max = 0;
    for (int i = 1; i <= L; ++i) {
      n = 0;
      for (int j = 1; j <= rear; ++j) {
        if (qu[j].l == i)
          ++n;
        if (max < n)
          max = n;
      }
      std::cout << max << "**" << std::endl;
    }
    return max;
  }
  return 0;
}

int main(int argc, char **argv) {
  BTNode *T;
  createTree(T);
  levelOrder(T);
  return 0;
}